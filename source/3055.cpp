#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int R, C, res;
queue<pair<int, int>> waterq;
queue<pair<int, int>> q;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void waterBfs(vector<vector<char>> &map, vector<vector<int>> &waterdist)
{
    while (!waterq.empty())
    {
        int x = waterq.front().first;
        int y = waterq.front().second;
        waterq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (waterdist[nx][ny] != -1)
                continue;
            if (map[nx][ny] == 'X'||map[nx][ny] == 'D')
                continue;
            if (map[nx][ny] == '.'||map[nx][ny] == 'S')
            {
                waterdist[nx][ny] = waterdist[x][y] + 1;
                waterq.push({nx, ny});
            }
        }
    }
}
int bfs(vector<vector<char>> &map, vector<vector<int>> &waterdist, vector<vector<int>> &dist)
{
    res = -1;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (map[x][y] == 'D')
        {
            res = dist[x][y];
            return res;
        }
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= R || ny >= C)
                continue;
            if (dist[nx][ny] != -1)
                continue;
            if (map[nx][ny] == 'X'||map[nx][ny]=='*')
                continue;
            if (dist[x][y]+1>=waterdist[nx][ny]&&waterdist[nx][ny]!=-1)
                continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
            
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    vector<vector<char>> map(R, vector<char>(C, '.'));
    vector<vector<int>> waterdist(R, vector<int>(C, -1));
    vector<vector<int>> dist(R, vector<int>(C, -1));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (map[i][j] == '*')
            {
                waterdist[i][j] = 0;
                waterq.push({i, j});
            }
            else if (map[i][j] == 'S')
            {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    waterBfs(map,waterdist);
    int res = bfs(map,waterdist,dist);
    if(res==-1)
        cout<<"KAKTUS";
    else
        cout<<res;

    return 0;
}