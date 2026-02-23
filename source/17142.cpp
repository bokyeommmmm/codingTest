#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, res, SIZE;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

vector<vector<int>> map;
vector<pair<int, int>> virus;
vector<int> visited;

int bfs()
{
    int days = 0;
    auto copy = map;
    queue<pair<int, int>> q;
    for (int i = 0; i < SIZE; i++)
    {
        if (visited[i] == 1)
        {
            q.push({virus[i].first, virus[i].second});
            copy[virus[i].first][virus[i].second] = 0;
        }
        else
        {
            copy[virus[i].first][virus[i].second] = -1;
        }
    }
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (nr < 0 || nc < 0 || nr >= N || nc >= N)
                continue;
            if (copy[nr][nc] != 0)
                continue;
            days = max(days, copy[r][c] + 1);
            copy[nr][nc] = copy[r][c] + 1;
            q.push({nr, nc});
        }
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (copy[i][j] == 0)
                return -1;
        }
    }
    return days;
}
void dfs(int idx, int cnt)
{
    if (cnt == M)
    {
        int tmp = bfs();
        if (tmp != -1)
        {
            res = min(res, tmp);
        }
    }
    if (idx == SIZE)
        return;
    visited[idx] = 1;
    dfs(idx + 1, cnt + 1);
    visited[idx] = 0;
    dfs(idx + 1, cnt);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    map.assign(N, vector<int>(N, 0));
    res = 100;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                temp = -1;
            }
            map[i][j] = temp;
            if (temp == 2)
            {
                virus.push_back({i, j});
            }
        }
    }
    SIZE = virus.size();
    visited.assign(SIZE, 0);
    dfs(0, 0);
    if (res == 100)
    {
        res = -1;
    }

    cout << res;
    return 0;
}
