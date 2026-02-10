#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int bfs(vector<vector<int>> &arr){

    int N = arr.size();
    vector<int> visited (N,0);
    queue<int> q;
    int res=0;
    
    visited[1]=1;
    q.push(1);
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int i = 0; i < arr[x].size(); i++)
        {
            int nx = arr[x][i];
            if(visited[nx]!=1)
            {
                visited[nx]=1;
                q.push(nx);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if(visited[i]==1)
            res++;
    }
    
    return res-1;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;  // N: 컴퓨터 수, M: 연결 쌍 수

    N++;
    vector<vector<int>> arr (N);
    for (int i = 0; i < M; i++)
    {
        int a,b;
        cin>>a>>b;

        arr[a].push_back(b);
        arr[b].push_back(a);

    }

    cout<<bfs(arr);
    
    return 0;
}
