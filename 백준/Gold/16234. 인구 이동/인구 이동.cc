#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;

int N, L, R;
int res;
vector<vector<int>> A;
vector<vector<int>> visited;
queue<pair<int, int>> q;
stack<pair<int, int>> area;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
bool is_moved;
void bfs()
{
    int sum = 0;
    int cnt = 0;
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        area.push({r, c});
        sum += A[r][c];
        cnt++;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nc < 0 || nr < 0 || nc >= N || nr >= N)
                continue;
            if (visited[nr][nc] != 0)
                continue;
            if (abs(A[nr][nc] - A[r][c]) > R || abs(A[nr][nc] - A[r][c]) < L)
                continue;
            visited[nr][nc] = 1;
            q.push({nr, nc});
        }
    }
    if (cnt > 1)
    {
        is_moved=true;
        while (!area.empty())
        {
            int r = area.top().first;
            int c = area.top().second;

            A[r][c] = sum / cnt;
            area.pop();
        }
    }
    else
        area.pop();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> L >> R;
    A.assign(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A[i][j];
        }
    }
    int res = 0;
    while (true)
    {
        is_moved = false;
        visited.assign(N, vector<int>(N, 0));

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (visited[i][j] == 0)
                {
                    q.push({i, j});
                    visited[i][j] = 1;
                    bfs();
                }
            }
        }
        if(is_moved==false)
        break;

        res++;
    }
    cout << res;
    return 0;
}