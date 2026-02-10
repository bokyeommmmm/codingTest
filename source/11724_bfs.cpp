#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>> &graph, vector<int> &visited, int x)
{
    queue<int> q;
    visited[x] = 1;
    q.push(x);

    while (!q.empty())
    {
        x = q.front();
        q.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            int nx = graph[x][i];
            if (visited[nx] == 0)
            {
                visited[nx] = 1;
                q.push(nx);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int res = 0;
    vector<vector<int>> graph(N + 1);
    vector<int> visited(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
    {
        if (visited[i] == 0)
        {
            res++;
            bfs(graph, visited, i);
        }
    }
    cout << res;
    return 0;
}
