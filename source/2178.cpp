#include <vector>
#include <string>
#include <iostream>
#include <queue>
using namespace std;

int N, M;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(int sx, int sy, vector<vector<int>> &arr)
{
    vector<vector<int>> dist(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<pair<int, int>> q;

    q.push(make_pair(sx, sy));
    visited[sx][sy] = 1;
    dist[sx][sy] = 1;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if (visited[nx][ny] == 1)
                continue;
            if(arr[nx][ny]==0)
                continue;

                visited[nx][ny]=1;
                dist[nx][ny]=dist[x][y]+1;
                q.push(make_pair(nx,ny));
        }
    }

    return dist[N-1][M-1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    vector<vector<int>> arr(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = s[j] - '0';
        }
    }
    cout << bfs(0, 0, arr);

    return 0;
}