#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, M;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, vector<vector<int>> &map, vector<vector<int>> &visited)
{
    visited[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
        if (map[nx][ny] == 0)
            continue;
        if (visited[nx][ny] == 1)
            continue;
        dfs(nx, ny, map, visited);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int cnt = 0;
        int K;
        cin >> N >> M >> K;
        vector<vector<int>> map(N, vector<int>(M, 0));
        vector<vector<int>> visited(N, vector<int>(M, 0));
        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            map[x][y] = 1;
        }
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < M; k++)
            {
                if (visited[j][k] == 0 && map[j][k] == 1)
                {
                    cnt++;
                    dfs(j, k, map, visited);
                }
            }
        }
        cout << cnt<<"\n";
    }

    return 0;
}
