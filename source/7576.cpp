#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>> &arr)
{
    int N = (int)arr.size();    // 행
    int M = (int)arr[0].size(); // 열
    vector<vector<int>> dist(N, vector<int>(M, 0));
    vector<vector<int>> visited(N, vector<int>(M, 0));
    queue<pair<int, int>> q;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 1)
            {
                visited[i][j] = 1;
                dist[i][j] = 0;
                q.push(make_pair(i, j));
            }
        }
    }
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

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
            if (arr[nx][ny] != 0)
                continue;
            visited[nx][ny] = 1;
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
    int answer = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0 && visited[i][j] == 0) return -1;
            answer = max(answer, dist[i][j]);
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int M, N;
    cin >> M >> N;

    vector<vector<int>> arr(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout<<bfs(arr);
    return 0;
}