#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, days;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

queue<pair<int, int>> qq;
vector<vector<int>> map;
vector<vector<int>> visited;

void air()
{
    queue<pair<int, int>> q;
    visited.assign(N, vector<int>(M, 0));

    q.push({0, 0});
    visited[0][0] = 1;
    map[0][0] = 2;

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M)
                continue;
            if (visited[nr][nc])
                continue;
            if (map[nr][nc] == 1)
                continue;

            visited[nr][nc] = 1;
            map[nr][nc] = 2;
            q.push({nr, nc});
        }
    }
}

void count(int r, int c)
{
    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (map[nr][nc] == 2)
            cnt++;
    }

    if (cnt >= 2)
        qq.push({r, c});
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    map.assign(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> map[i][j];

    while (true)
    {
        air();

        while (!qq.empty())
            qq.pop();

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (map[i][j] == 1)
                    count(i, j);
            }
        }

        if (qq.empty())
        {
            cout << days;
            return 0;
        }

        days++;

        while (!qq.empty())
        {
            int r = qq.front().first;
            int c = qq.front().second;
            qq.pop();
            map[r][c] = 0;
        }
    }

    return 0;
}
