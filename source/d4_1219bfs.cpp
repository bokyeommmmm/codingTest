#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int res;
queue<int>q;
void bfs(int sx, vector<vector<int>> &graph, vector<int> &visited)
{
    while(!q.empty())
    {
        int x = q.front();
        if(x==99){
            res=1;
            return;
        }
        q.pop();
        for (int i = 0; i < graph[x].size(); i++)
        {
            int nx = graph[x][i];
            if (visited[nx]==1)
                continue;
            visited[nx]=1;
            q.push(nx);
        }
        
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
        while (!q.empty()) q.pop();
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

        visited[0]=1;
        q.push(0);
        bfs(0,graph,visited);
        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}