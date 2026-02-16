#include <iostream>
#include <vector>
using namespace std;

int N, M, res;
vector<vector<int>> graph;
vector<int> visited;

void dfs(int from)
{
    for (int i = 0; i < graph[from].size(); i++)
    {
        int to = graph[from][i];
        if (visited[to] == 1)
            continue;
        visited[to] = 1;
        dfs(to);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N >> M;

        graph.assign(N + 1, vector<int>(0));
        visited.assign(N + 1, 0);
        res = 0;
        for (int i = 0; i < M; i++)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            graph[to].push_back(from);
        }
        for (int i = 1; i <= N; i++)
        {
            if (visited[i] == 0)
            {
                res++;
                dfs(i);
            }
        }
        cout<<"#"<<tc<<" "<<res<<"\n";
    }

    return 0;
}