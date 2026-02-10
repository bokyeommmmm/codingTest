#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// BOJ 14501 퇴사
// dp[i] = i번째 날부터 퇴사일까지 얻을 수 있는 최대 이익
// 선택:
// 1) i번째 상담 수행 (가능하면): P[i] + dp[i + T[i]]
// 2) i번째 상담 건너뜀: dp[i + 1]

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> T(N + 2, 0), P(N + 2, 0);
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    vector<int> dp(N + 2, 0);

    // 뒤에서부터 계산
    for (int i = N; i >= 1; i--) {
        int next = i + T[i];

        // 기본: 상담을 안 한다
        dp[i] = dp[i + 1];

        // 상담을 할 수 있으면(퇴사 전까지 끝나면)
        if (next <= N + 1) {
            dp[i] = max(dp[i], P[i] + dp[next]);
        }
    }

    cout << dp[1];
    return 0;
}
