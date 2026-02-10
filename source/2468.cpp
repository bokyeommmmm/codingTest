#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y, vector<vector<int>> &map, vector<vector<int>> &visited,int h)
{
    visited[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (visited[nx][ny] == 1)
            continue;
        if (map[nx][ny] < h)
            continue;
        dfs(nx, ny, map, visited,h);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    int cnt = 0;
    int max_cnt = 0;
    int max_height = 0;
    vector<vector<int>> map(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> map[i][j];
            max_height = max(map[i][j], max_height);
        }
    }
    for (int h = 0; h <= max_height; h++)
    {
        vector<vector<int>> visited(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == 0 && map[i][j] >= h)
                {
                    cnt++;
                    dfs(i, j, map, visited,h);
                }
            }
        }
        max_cnt = max(cnt, max_cnt);
        cnt=0;
    }
    cout<<max_cnt;

    return 0;
}