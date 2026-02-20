#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T, N;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		vector<vector<int>>arr(2, vector<int>(N, 0));
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> arr[i][j];
			}

		}
		vector<vector<int>>dp(2, vector<int>(N, 0));
		if (N == 1)
		{
			cout << max(arr[0][0], arr[1][0]) << "\n";
			continue;
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = max(arr[0][1] + dp[1][0], dp[0][0]);
		dp[1][1] = max(arr[1][1] + dp[0][0], dp[1][0]);
		if (N == 2)
		{
			cout << max(dp[0][1], dp[1][1]) << "\n";
			continue;
		}
		for (int j = 2; j < N; j++)
		{
			dp[0][j] = max(max(dp[0][j - 1], arr[0][j] + dp[1][j - 1]), arr[0][j] + max(dp[0][j - 2], dp[1][j - 2]));
			dp[1][j] = max(max(dp[1][j - 1], arr[1][j] + dp[0][j - 1]), arr[1][j] + max(dp[0][j - 2], dp[1][j - 2]));
		}
		cout << max(dp[0][N - 1], dp[1][N - 1]) << "\n";
		
	}
	return 0;
}