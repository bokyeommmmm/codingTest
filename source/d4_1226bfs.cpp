#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int res;
queue<pair<int, int>> q;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfs(vector<vector<char>> &maze, vector<vector<int>> &visited)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (maze[x][y] == '3')
        {
            res = 1;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= 16 || ny >= 16)
                continue;
            if (maze[nx][ny] == '1')
                continue;
            if (visited[nx][ny] == 1)
                continue;
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 1; tc <= 10; tc++)
    {
        int a;
        cin >> a;
        res = 0;
        if (!q.empty())
            q.pop();
        vector<vector<char>> maze(16, vector<char>(16, 0));
        vector<vector<int>> visited(16, vector<int>(16, 0));

        for (int i = 0; i < 16; i++)
        {
            string s;
            cin >> s;
            for (int j = 0; j < 16; j++)
            {
                maze[i][j] = s[j];
            }
        }

        for (int i = 0; i < 16; i++)
        {
            for (int j = 0; j < 16; j++)
            {
                if (maze[i][j] == '2')
                {
                    visited[i][j] = 1;
                    q.push({i, j});
                }
            }
        }
        bfs(maze, visited);
        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}
