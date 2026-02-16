#include <iostream>
#include <vector>
using namespace std;

int N, res;
vector<int> arr;
vector<int> visited;

void dfs(int left, int right, int cnt)
{
    if (cnt == N)
    {
        res++;
        return;
    }
    for (int i = 0; i < N; i++)
    {
        int weight = arr[i];
        if (visited[i] == 1)
            continue;
        if (left >= right + weight)
        {
            visited[i] = 1;
            dfs(left, right + weight, cnt + 1);
            visited[i] = 0;
        }
        visited[i] = 1;
        dfs(left + weight, right, cnt + 1);
        visited[i] = 0;
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
        cin >> N;
        arr.clear();
        visited.assign(N, 0);
        res = 0;
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        dfs(0, 0, 0);

        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}