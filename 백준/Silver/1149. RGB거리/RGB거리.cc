#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	vector<vector<int>>arr(N+1, vector<int>(3, 0));
	vector<int>rgb(3, 0);
	for (int i = 1; i <= N; i++)
	{
		cin >> rgb[0] >> rgb[1] >> rgb[2];
		arr[i] = rgb;
	}
	vector<vector<int>>dp(N+1, vector<int>(3, 0));
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (j == 0) //이번에 r
			{
				dp[i][j] = arr[i][j] + min(dp[i - 1][1], dp[i - 1][2]); //직전 g,b중 싼거
			}
			else if (j == 1) //g
			{
				dp[i][j] = arr[i][j] + min(dp[i - 1][0], dp[i - 1][2]);

			}
			else //b
			{
				dp[i][j] = arr[i][j] + min(dp[i - 1][1], dp[i - 1][0]);

			}
		}
	}
	cout << min(dp[N][0],min(dp[N][1],dp[N][2]));
	return 0;
}
