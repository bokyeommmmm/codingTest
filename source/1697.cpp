#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int bfs(int sx, int y)
{

    vector<int> visited(100001, 0);
    vector<int> dist(100001, 0);
    queue<int> q;

    visited[sx] = 1;
    dist[sx]=0;
    q.push(sx);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        if (x == y)
            return dist[x];
        int next[3] = {x - 1, x + 1, x * 2};
        for (int i = 0; i < 3; i++)
        {

            int nx = next[i];
            if (nx < 0 || nx > 100000)
                continue;
            if (visited[nx] == 1)
                continue;

            dist[nx] = dist[x] + 1;
            visited[nx] = 1;
            q.push(nx);
        }
    }

    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    cin >> N >> K;

    cout << bfs( N, K);

    return 0;
}