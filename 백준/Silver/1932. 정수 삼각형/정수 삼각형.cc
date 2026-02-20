#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<vector<int>>arr(N + 1, vector<int>(N, 0));
	vector<vector<int>>dp(N + 1, vector<int>(N, 0));
	cin >> arr[1][0];
	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[1][0] = arr[1][0];
	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = arr[i][0]+dp[i - 1][0];
		dp[i][i - 1] = arr[i][i - 1] + dp[i - 1][i - 2];
		for (int j = 1; j < i-1; j++)
		{
			dp[i][j] = arr[i][j] + max(dp[i - 1][j-1], dp[i - 1][j]);
		}
	}
	sort(dp[N].begin(), dp[N].end());
	cout << dp[N][N - 1];
}