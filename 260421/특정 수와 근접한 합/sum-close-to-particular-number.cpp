#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, S, res;
vector<int> arr;
vector<int> arr2;

void dfs(int idx, int cnt)
{
    if (idx == N)
    {
        if (cnt == 2)
        {
            int sum = 0;
            for (int i = 0; i < N - 2; i++)
            {
                sum += arr2[i];
            }
            res = min(res, abs(sum - S));
        }
        return;
    }
    arr2.push_back(arr[idx]);
    dfs(idx + 1, cnt);
    arr2.pop_back();
    dfs(idx + 1, cnt + 1);
}

int main()
{
    cin >> N >> S;
    res = 1000000000;

    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    dfs(0, 0);

    cout << res;
    return 0;
}