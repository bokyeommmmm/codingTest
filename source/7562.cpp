#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

void bfs(int L)
{
    queue<pair<int, int>> q;
    int sx, sy, xx, yy;
    vector<vector<int>> visited(L, vector<int>(L, -1));
    cin >> sx >> sy >> xx >> yy;
    visited[sx][sy] = 0;
    q.push(make_pair(sx, sy));
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        if (x == xx && y == yy)
        {
            cout << visited[x][y] << "\n";
            return;
        }

        q.pop();
        for (int i = 0; i < 8; i++)
        {

            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || ny >= L || nx >= L)
                continue;
            if (visited[nx][ny] != -1)
                continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int L;
        cin >> L;

        bfs(L);
    }

    return 0;
}