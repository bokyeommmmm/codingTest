#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int R, C, maxCnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt, vector<vector<char>> &map, vector<bool> &visited)
{
    visited[map[x][y] - 'A'] = true;
    cnt++;
    maxCnt = max(maxCnt,cnt);
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= R || ny >= C)
            continue;
        if (visited[map[nx][ny] - 'A'])
            continue;
        visited[map[nx][ny] - 'A'] = true;
        dfs(nx,ny,cnt,map,visited);
        visited[map[nx][ny] - 'A'] = false;
    }
}

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    vector<vector<char>> map(R, vector<char>(C, '.'));
    vector<bool> visited(26, false);
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }

    dfs(0, 0, 0, map, visited);

    cout<<maxCnt;
    return 0;
}