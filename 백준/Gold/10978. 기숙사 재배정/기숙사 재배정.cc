#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> dp(21, 0);

    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= 20; i++)
    {
        dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        cout << dp[temp] << "\n";
    }

    return 0;
}