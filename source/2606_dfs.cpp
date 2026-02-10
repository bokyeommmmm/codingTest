#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<vector<int>> &arr, vector<int> &visited, int x)
{

    visited[x] = 1;
    for (int i = 0; i < arr[x].size(); i++)
    {
        int nx = arr[x][i];
        if (visited[nx] != 1)
        {
            dfs(arr, visited, nx);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N + 1);
    vector<int> visited(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    dfs(arr, visited, 1);
    int res = 0;
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == 1)
            res++;
    }

    cout << res - 1;
}
