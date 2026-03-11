#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, L;
vector<pair<int, int>> info; // 점수, 칼로리
vector<vector<int>> dp;

void init()
{
	cin >> N >> L;
	info.clear();

	for (int i = 0; i < N; i++)
	{
		int t, k;
		cin >> t >> k;
		info.push_back({ t, k });
	}

	dp.assign(N + 1, vector<int>(L + 1, 0));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int TC;
	cin >> TC;

	for (int tc = 1; tc <= TC; tc++)
	{
		init();

		for (int i = 1; i <= N; i++)
		{
			int taste = info[i - 1].first;
			int cal = info[i - 1].second;

			for (int j = 0; j <= L; j++)
			{
				// 이번거 안넣음
				dp[i][j] = dp[i - 1][j];

				// 이번거 넣음 
				if (j >= cal)
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j - cal] + taste);
				}
			}
		}

		cout << "#" << tc << " " << dp[N][L] << "\n";
	}

	return 0;
}