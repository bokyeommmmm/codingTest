#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, S;
    cin >> N >> S;

    vector<int> arr(N);
    int total = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }

    int res = 1000000000;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int remain = total - arr[i] - arr[j];
            res = min(res, abs(remain - S));
        }
    }

    cout << res;
    return 0;
}