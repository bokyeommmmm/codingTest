#include <iostream>
#include <vector>

using namespace std;

int N, M;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {1, 0, -1, 0, -1, 1, -1, 1};

void dfs(int x, int y, vector<vector<int>> &map, vector<vector<int>> &visited)
{
    visited[x][y] = 1;

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
            continue;
        if (visited[nx][ny] == 1)
            continue;
        if (map[nx][ny] == 0)
            continue;
        dfs(nx, ny, map, visited);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (;;)
    {
        int cnt = 0;
        cin >> M >> N;
        if (N == 0 && M == 0)
            return 0;

        vector<vector<int>> map(N, vector<int>(M, 0));
        vector<vector<int>> visited(N, vector<int>(M, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> map[i][j];
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (visited[i][j] == 0 && map[i][j] == 1)
                {
                    cnt++;
                    dfs(i, j, map, visited);
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}