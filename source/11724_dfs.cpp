#include<iostream>
#include<vector>

using namespace std;
void dfs(vector<vector<int>> &graph,vector<int> &visited,int x){
    visited[x]=1;
    for (int i = 0; i < graph[x].size(); i++)
    {
        int nx = graph[x][i];

        if(visited[nx]==0){
            dfs(graph,visited,nx);
        }
    }
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M;
    cin>>N>>M;
int res = 0;
    vector<vector<int>> graph(N+1);
    vector<int> visited (N+1,0);
    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin>>a>>b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    for (int i = 1; i <= N; i++)
    {
        if(visited[i]==0){
            res++;
            dfs(graph,visited,i);
        }
    }
    cout<<res;
    return 0;
}