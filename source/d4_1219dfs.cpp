#include <iostream>
#include <vector>

using namespace std;

int res;

void dfs(int x, vector<vector<int>> &graph, vector<int> &visited)
{
    if (x == 99)
    {
        res = 1;
        return;
    }
    visited[x] = 1;
    for (int i = 0; i < graph[x].size(); i++)
    {
        int nx = graph[x][i];

        if (visited[nx] == 1)
            continue;

        dfs(nx, graph, visited);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 1; tc <= 10; tc++)
    {
        int a;
        cin >> a;
        res = 0;
        vector<vector<int>> graph(100);
        vector<int> visited(100, -1);
        cin >> a;
        for (int i = 0; i < a; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }

        dfs(0, graph, visited);
        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}