#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
int map[25][25];
bool visited[25][25];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int cnt;

void dfs(int x, int y) {
    visited[x][y] = true;
    cnt++;

    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if (visited[nx][ny]) continue;
        if (map[nx][ny] == 0) continue;

        dfs(nx, ny);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++) {
            map[i][j] = s[j] - '0';
        }
    }

    vector<int> result;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (map[i][j] == 1 && !visited[i][j]) {
                cnt = 0;
                dfs(i, j);
                result.push_back(cnt);
            }
        }
    }

    sort(result.begin(), result.end());

    cout << result.size() << "\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }

    return 0;
}
