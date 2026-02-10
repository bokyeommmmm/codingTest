#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<int>> dist;

// 상, 우, 하, 좌
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin >> N >> M;
    board.assign(N, vector<int>(M, 0));
    dist.assign(N, vector<int>(M, -1)); // -1이면 아직 방문X

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> board[i][j];

    queue<pair<int,int>> q;
    q.push(make_pair(0, 0));
    dist[0][0] = 0;

    while (!q.empty()) {
        pair<int,int> cur = q.front();
        q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (dist[nx][ny] != -1) continue;
            if (board[nx][ny] == 1) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    cout << dist[N-1][M-1]; // 도착점 최단거리 (못 가면 -1)
}
