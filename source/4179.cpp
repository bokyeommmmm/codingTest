#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
queue<pair<int, int>> q;
int R, C;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
void bfsF(vector<vector<char>> &maze, vector<vector<int>> &distF)
{

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (distF[nx][ny] >= 0)
                continue;
            if (maze[nx][ny] == '#')
                continue;

            distF[nx][ny] = distF[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}
int bfsJ(vector<vector<char>> &maze, vector<vector<int>> &distF, vector<vector<int>> &distJ)
{
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                return distJ[x][y] + 1;
            if (distJ[nx][ny] >= 0)
                continue;
            if (maze[nx][ny] == '#')
                continue;
            if (distJ[x][y] + 1 >= distF[nx][ny] && distF[nx][ny] != -1)
                continue;

            distJ[nx][ny] = distJ[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

    return -1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    vector<vector<char>> maze(R, vector<char>(C, '#'));
    vector<vector<int>> distF(R, vector<int>(C, -1));
    vector<vector<int>> distJ(R, vector<int>(C, -1));

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (maze[i][j] == 'F')
            {
                distF[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    bfsF(maze, distF);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (maze[i][j] == 'J')
            {
                distJ[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    int res = bfsJ(maze, distF, distJ);
    if (res == -1)
        cout << "IMPOSSIBLE";
    else
        cout << res;

    return 0;
}