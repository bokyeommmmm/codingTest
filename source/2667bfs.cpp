#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

int N;
int mapArr[25][25];
bool visited[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int sx, int sy) {
    queue<pair<int,int>> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = true;

    int cnt = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny]) continue;
            if (mapArr[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            q.push(make_pair(nx, ny));
            cnt++;
        }
    }

    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            mapArr[i][j] = s[j] - '0';
        }
    }

    vector<int> result;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (mapArr[i][j] == 1 && !visited[i][j]) {
                int size = bfs(i, j);
                result.push_back(size);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < (int)result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
