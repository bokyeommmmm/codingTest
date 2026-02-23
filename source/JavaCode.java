package samsung01;

import java.net.*;
import java.io.*;
import java.util.*;

/**
 * ================================
 * 일타싸피 당구 "만능 템플릿" (목적구 1개 기준)
 * ================================
 *
 * ✅ 목표
 *  - 목적구(target)를 가장 가까운 홀(Hole)에 넣기
 *  - 큐볼(my ball)은 "목적구를 홀 방향으로 보내기 위한 접점(contact point)"을 향해 이동
 *  - DIRECT(직선) + 1쿠션(상/하/좌/우) 후보를 모두 만들고 가장 좋은(기본: 최단거리) 후보를 선택
 *
 * ✅ 이 코드 한 파일만 들고 가서 해야 할 일(시험장)
 *  1) 서버 입력 포맷이 다르면 parseStateFromLine()만 수정
 *  2) 서버 출력 포맷이 다르면 buildSendString()만 수정
 *  3) 각도 기준이 다르면 ANGLE_MODE만 변경(0~3)
 *
 * ✅ 이 코드가 커버하는 것
 *  - 테이블 규격 254x127
 *  - 공 직경 5.73, 홀 위치 오프셋 +3
 *  - 목적구 위치가 어디든(좌상/우상/우하/좌하/중앙/벽 근처 등)
 *  - 직선이 애매하면 1쿠션(정사영/대칭) 자동 고려
 *  - 접점이 테이블 밖으로 나가면: 다른 홀 후보로 재시도
 *
 * ⚠️ 이 코드가 일부러 "안 하는 것"
 *  - 마찰/반발계수 기반 물리 시뮬레이션(값 제공 안 되는 유형이라 가정)
 *  - 다른 공(장애물) 충돌 체크(목적구 1개 전제)
 */
public class JavaCode {

    // =========================
    // 통신 기본 (제공된 코드 기반)
    // =========================
    static final String NICKNAME = "자바플레이어";
    static final String HOST = "127.0.0.1";
    static final int PORT = 1447;
    static final int CODE_SEND = 9901;

    // =========================
    // 규격(문서에서 주어진 값)
    // =========================
    static final double TABLE_W = 254.0;
    static final double TABLE_H = 127.0;

    // 공 직경(센터-센터 충돌 거리로 사용)
    static final double BALL_DIAMETER = 5.73;

    // 홀은 좌표 영역 바깥에 실제 위치가 +3 정도 있다고 안내됨
    static final double HOLE_OFFSET = 3.0;

    // 파워 범위 (시험 규칙이 다르면 여기 조정)
    static final double POWER_MIN = 5.0;
    static final double POWER_MAX = 100.0;

    // 테이블 밖으로 접점이 크게 벗어나면 무효로 볼 기준(너무 빡세게 잡지 말 것)
    static final double OUT_MARGIN = 2.0;

    // =========================
    // 각도 기준(시험장 대응 핵심)
    // =========================
    /**
     * ANGLE_MODE:
     *  0) 0도 = 오른쪽(+x), 반시계(CCW) 증가  (수학 표준 atan2)
     *  1) 0도 = 오른쪽(+x), 시계(CW) 증가
     *  2) 0도 = 위쪽(+y),   반시계(CCW) 증가
     *  3) 0도 = 위쪽(+y),   시계(CW) 증가
     *
     * ✅ 시험장에서 각도가 이상하면 이것만 바꿔서 바로 맞출 수 있게 설계.
     */
    static int ANGLE_MODE = 0;

    // =========================
    // 홀 좌표 (4코너)
    // =========================
    // 좌하, 우하, 좌상, 우상
    static final double[][] HOLES = {
            {-HOLE_OFFSET, -HOLE_OFFSET},
            {TABLE_W + HOLE_OFFSET, -HOLE_OFFSET},
            {-HOLE_OFFSET, TABLE_H + HOLE_OFFSET},
            {TABLE_W + HOLE_OFFSET, TABLE_H + HOLE_OFFSET}
    };

    // =========================
    // 상태 구조
    // =========================
    static class GameState {
        // 내 공
        double myX, myY;

        // 목적구(1개)
        double targetX, targetY;

        // (선택) stage 값이 서버에서 오면 저장해두면 디버깅에 좋음
        int stage = 1;
    }

    // =========================
    // 후보 경로 종류
    // =========================
    enum Wall { DIRECT, LEFT, RIGHT, BOTTOM, TOP }

    // =========================
    // 한 턴 플랜(결과)
    // =========================
    static class Plan {
        Wall wall;          // DIRECT 또는 1쿠션 벽
        double angleDeg;    // 서버에 보낼 각도(도 단위)
        double power;       // 서버에 보낼 파워
        double len;         // 선택된 경로의 "대칭점까지" 거리(파워 추정용)
        double holeX, holeY;// 선택한 홀
        double aimX, aimY;  // 큐볼이 조준해야 하는 접점(또는 그 대칭점)
    }

    // =========================
    // Math 유틸
    // =========================
    static double sq(double v) { return v * v; }

    static double dist(double x1, double y1, double x2, double y2) {
        return Math.sqrt(sq(x2 - x1) + sq(y2 - y1));
    }

    static double clamp(double v, double lo, double hi) {
        return Math.max(lo, Math.min(hi, v));
    }

    static double normalizeDeg360(double deg) {
        deg %= 360.0;
        if (deg < 0) deg += 360.0;
        return deg;
    }

    /**
     * 수학 표준 각도:
     *  - Math.atan2(dy, dx)
     *  - 0도 = +x(오른쪽), 반시계(CCW) 증가
     */
    static double mathAngleDeg(double x1, double y1, double x2, double y2) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        double rad = Math.atan2(dy, dx);
        double deg = rad * 180.0 / Math.PI;
        return normalizeDeg360(deg);
    }

    /**
     * 시험 각도 기준으로 변환
     */
    static double toGameAngleDeg(double mathDeg) {
        double a;
        if (ANGLE_MODE == 0) {          // 오른쪽 0, CCW
            a = mathDeg;
        } else if (ANGLE_MODE == 1) {   // 오른쪽 0, CW
            a = 360.0 - mathDeg;
        } else if (ANGLE_MODE == 2) {   // 위쪽 0, CCW
            a = mathDeg - 90.0;
        } else {                         // 위쪽 0, CW
            a = 90.0 - mathDeg;
        }
        return normalizeDeg360(a);
    }

    // =========================
    // 1) "가까운 홀" 선택 (정렬해서 시도)
    // =========================
    static int[] holesByDistance(double tx, double ty) {
        // 0..3 인덱스를 거리순 정렬해 반환
        Integer[] idx = {0, 1, 2, 3};
        Arrays.sort(idx, (a, b) -> {
            double da = dist(tx, ty, HOLES[a][0], HOLES[a][1]);
            double db = dist(tx, ty, HOLES[b][0], HOLES[b][1]);
            return Double.compare(da, db);
        });
        int[] out = new int[4];
        for (int i = 0; i < 4; i++) out[i] = idx[i];
        return out;
    }

    // =========================
    // 2) 목적구를 홀로 보내기 위한 "접점(contact point)" 계산
    // =========================
    /**
     * 목적구(target)가 홀(hole)로 가려면:
     *  - target -> hole 방향 단위벡터 u
     *  - 큐볼 중심은 target 중심에서 "반대 방향으로 공 직경"만큼 떨어진 지점을 향해야 함
     *    (두 공 중심 간 거리 = 공 직경)
     */
    static double[] contactPoint(double tx, double ty, double hx, double hy) {
        double vx = hx - tx;
        double vy = hy - ty;
        double len = Math.sqrt(vx * vx + vy * vy);
        if (len < 1e-9) {
            // 홀과 target이 거의 겹치면 그냥 target을 반환(극단 케이스)
            return new double[]{tx, ty};
        }
        vx /= len;
        vy /= len;

        double cx = tx - vx * BALL_DIAMETER;
        double cy = ty - vy * BALL_DIAMETER;
        return new double[]{cx, cy};
    }

    // 접점이 테이블 안쪽(약간의 여유 포함)에 있는지 검사
    static boolean isInsideTableLoose(double x, double y) {
        return (x >= -OUT_MARGIN && x <= TABLE_W + OUT_MARGIN &&
                y >= -OUT_MARGIN && y <= TABLE_H + OUT_MARGIN);
    }

    // =========================
    // 3) 1쿠션: 대칭(mirror)으로 직선화
    // =========================
    /**
     * 목표점(aim)을 벽에 대해 대칭시키면,
     * 내 공 -> (대칭점) 직선은 실제로는 벽을 1번 튕기는 경로와 동일한 각도를 제공.
     *
     * LEFT   : x -> -x
     * RIGHT  : x -> 2W - x
     * BOTTOM : y -> -y
     * TOP    : y -> 2H - y
     */
    static double[] mirror(double x, double y, Wall w) {
        double mx = x, my = y;
        if (w == Wall.LEFT)   mx = -x;
        if (w == Wall.RIGHT)  mx = 2.0 * TABLE_W - x;
        if (w == Wall.BOTTOM) my = -y;
        if (w == Wall.TOP)    my = 2.0 * TABLE_H - y;
        return new double[]{mx, my};
    }

    // =========================
    // 4) DIRECT + 1쿠션 후보 생성/선택
    // =========================
    static class Candidate {
        Wall wall;
        double aimX, aimY;   // DIRECT면 접점, 쿠션이면 접점의 대칭점
        double length;       // 내 공 -> aim(대칭점) 거리 (비교 기준)
        double angleGame;    // 게임 기준 각도(도)
    }

    /**
     * "내 공(bx,by)이 접점(cx,cy)을 향해야 한다"는 조건 하에서,
     * DIRECT + (좌/우/하/상) 1쿠션의 대칭점을 만들어 후보를 만들고,
     * 가장 좋은 후보를 하나 선택한다.
     *
     * 기본 선택 기준: length 최소(짧을수록 파워 조절 쉬움)
     */
    static Candidate bestCuePath(double bx, double by, double cx, double cy) {
        Wall[] walls = {Wall.DIRECT, Wall.LEFT, Wall.RIGHT, Wall.BOTTOM, Wall.TOP};

        Candidate best = null;

        for (Wall w : walls) {
            double ax, ay;
            if (w == Wall.DIRECT) {
                ax = cx; ay = cy;
            } else {
                double[] m = mirror(cx, cy, w);
                ax = m[0]; ay = m[1];
            }

            double L = dist(bx, by, ax, ay);
            double mathDeg = mathAngleDeg(bx, by, ax, ay);
            double gameDeg = toGameAngleDeg(mathDeg);

            Candidate cand = new Candidate();
            cand.wall = w;
            cand.aimX = ax;
            cand.aimY = ay;
            cand.length = L;
            cand.angleGame = gameDeg;

            // 여기서 "쿠션 후보를 과감히 제한"하고 싶으면 조건 추가 가능.
            // 예: stage 1~4는 DIRECT 우선, DIRECT가 너무 이상할 때만 쿠션 허용 등.
            // 지금은 '진짜 만능'을 위해 일단 전부 비교.

            if (best == null || cand.length < best.length) best = cand;
        }

        return best;
    }

    // =========================
    // 5) 파워 결정(간단한 거리 스케일)
    // =========================
    /**
     * 마찰/반발 값이 제공되지 않는 유형을 가정하므로,
     * "거리 기반 스케일"로만 파워를 만든다.
     *
     * - 너무 약하면 도중에 멈추고
     * - 너무 강하면 튕김/오버런 가능
     *
     * diag(대각선)을 기준으로 40~100 사이로 스케일.
     */
    static double powerFromLength(double length) {
        double diag = Math.sqrt(TABLE_W * TABLE_W + TABLE_H * TABLE_H);
        double ratio = (diag < 1e-9) ? 0.5 : (length / diag); // 0~1 근사
        double p = 40.0 + 60.0 * ratio; // 40~100 근사
        return clamp(p, POWER_MIN, POWER_MAX);
    }

    // =========================
    // 6) 최종 플랜: 홀 선택(가까운 순으로) -> 접점 -> 후보 경로 -> 플랜 확정
    // =========================
    static Plan makePlan(GameState st) {
        double bx = st.myX, by = st.myY;
        double tx = st.targetX, ty = st.targetY;

        // 홀을 가까운 순으로 시도한다.
        // 접점이 테이블 밖으로 너무 나가는 홀은 버리고 다음 홀로 넘어가서 "안전한 접점"을 찾는다.
        int[] holeOrder = holesByDistance(tx, ty);

        Plan bestPlan = null;

        for (int k = 0; k < holeOrder.length; k++) {
            int hi = holeOrder[k];
            double hx = HOLES[hi][0], hy = HOLES[hi][1];

            // (1) 이 홀로 넣기 위한 접점 계산
            double[] cp = contactPoint(tx, ty, hx, hy);
            double cx = cp[0], cy = cp[1];

            // (2) 접점이 너무 이상하면(테이블에서 너무 멀면) 다음 홀 시도
            if (!isInsideTableLoose(cx, cy)) {
                continue;
            }

            // (3) 큐볼 -> 접점 경로: DIRECT + 1쿠션 후보 중 선택
            Candidate cand = bestCuePath(bx, by, cx, cy);

            // (4) 파워
            double power = powerFromLength(cand.length);

            Plan p = new Plan();
            p.wall = cand.wall;
            p.angleDeg = cand.angleGame;
            p.power = power;
            p.len = cand.length;
            p.holeX = hx; p.holeY = hy;
            p.aimX = cand.aimX; p.aimY = cand.aimY;

            // 여러 홀 중에서 어떤 플랜이 "최종"인지 기준:
            // - 기본은 가장 가까운 홀을 우선 시도하되,
            // - 여기서는 "플랜 길이가 더 짧은 것"을 선택 (안정성 위주)
            if (bestPlan == null || p.len < bestPlan.len) {
                bestPlan = p;
            }
        }

        // 만약 모든 홀에서 접점이 이상하게 튀면(극단 케이스),
        // 그냥 target 자체를 aim으로 보고 가장 가까운 홀 기준으로 단순샷(최후의 보험)
        if (bestPlan == null) {
            double[] hole = HOLES[0];
            double hx = hole[0], hy = hole[1];

            Candidate cand = bestCuePath(st.myX, st.myY, st.targetX, st.targetY);
            Plan p = new Plan();
            p.wall = cand.wall;
            p.angleDeg = cand.angleGame;
            p.power = powerFromLength(cand.length);
            p.len = cand.length;
            p.holeX = hx; p.holeY = hy;
            p.aimX = cand.aimX; p.aimY = cand.aimY;
            bestPlan = p;
        }

        return bestPlan;
    }

    // =========================
    // (시험장 수정 포인트 1) 입력 파싱
    // =========================
    /**
     * ✅ 가장 중요한 교체 지점
     *
     * 서버가 보내는 한 줄(line)이 어떤 포맷인지에 따라 파싱이 달라진다.
     * 이 템플릿은 "숫자만 뽑아서 순서대로" 매핑한다.
     *
     * [가정 A] stage/myX/myY/targetX/targetY/
     * [가정 B] myX myY targetX targetY
     * [가정 C] myX,myY,targetX,targetY
     *
     * 실제가 다르면 여기만 고치면 됨.
     */
    static GameState parseStateFromLine(String line) {
        GameState st = new GameState();

        // 숫자 토큰 추출
        List<Double> nums = new ArrayList<>();
        String[] tok = line.trim().split("[/ ,]+"); // /, 공백, 쉼표 기준 분리
        for (String t : tok) {
            if (t.isEmpty()) continue;
            try {
                nums.add(Double.parseDouble(t));
            } catch (NumberFormatException ignored) {}
        }

        // 매핑(가정)
        if (nums.size() >= 5) {
            st.stage = (int)Math.round(nums.get(0));
            st.myX = nums.get(1);
            st.myY = nums.get(2);
            st.targetX = nums.get(3);
            st.targetY = nums.get(4);
        } else if (nums.size() >= 4) {
            st.stage = 1;
            st.myX = nums.get(0);
            st.myY = nums.get(1);
            st.targetX = nums.get(2);
            st.targetY = nums.get(3);
        } else {
            // 디버그 기본값(실전에서는 거의 안 옴)
            st.myX = 30; st.myY = 20;
            st.targetX = 200; st.targetY = 100;
        }

        return st;
    }

    // =========================
    // (시험장 수정 포인트 2) 출력 포맷
    // =========================
    /**
     * 서버가 요구하는 출력이 예를 들어:
     *  - "angle/power/"
     *  - "angle power"
     *  - "power/angle/"
     * 등일 수 있다.
     *
     * ✅ 형식이 다르면 여기만 바꾸면 된다.
     */
    static String buildSendString(double angleDeg, double power) {
        // 가장 흔한 포맷 예시: angle/power/
        return String.format(Locale.US, "%.2f/%.2f/", angleDeg, power);
    }

    // =========================
    // 메인(통신 루프)
    // =========================
    public static void main(String[] args) {
        Socket socket = null;

        try {
            socket = new Socket();
            socket.connect(new InetSocketAddress(HOST, PORT));

            InputStream is = socket.getInputStream();
            OutputStream os = socket.getOutputStream();

            // 1) 인증
            String hello = CODE_SEND + "/" + NICKNAME + "/";
            os.write(hello.getBytes("UTF-8"));
            os.flush();

            // 2) 수신 루프
            BufferedReader br = new BufferedReader(new InputStreamReader(is, "UTF-8"));

            while (true) {
                String line = br.readLine();
                if (line == null) break;

                line = line.trim();
                if (line.isEmpty()) continue;

                // 종료 신호가 있는 유형이면 여기서 처리
                if (line.equalsIgnoreCase("END") || line.equalsIgnoreCase("QUIT")) break;

                // (A) 입력 파싱
                GameState st = parseStateFromLine(line);

                // (B) 플랜 생성
                Plan plan = makePlan(st);

                // (C) 출력 문자열 만들기
                String send = buildSendString(plan.angleDeg, plan.power);

                // (D) 전송
                os.write(send.getBytes("UTF-8"));
                os.flush();

                // ===== 디버그(시험장에서는 주석 가능) =====
                // System.out.println("[RECV] " + line);
                // System.out.printf(Locale.US,
                //         "[PLAN] stage=%d hole=(%.1f,%.1f) wall=%s aim=(%.2f,%.2f) angle=%.2f power=%.2f len=%.2f%n",
                //         st.stage, plan.holeX, plan.holeY, plan.wall.name(),
                //         plan.aimX, plan.aimY, plan.angleDeg, plan.power, plan.len);
            }

            os.close();
            is.close();
            socket.close();

        } catch (Exception e) {
            e.printStackTrace();
            try { if (socket != null) socket.close(); } catch (Exception ignored) {}
        }
    }
}