#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<int>> map;
int profit;
void getServiceArea(int r, int c, int k) //마름모 완료
{
	for (int i = r - k + 1; i <= r + k - 1; i++)
	{
		for (int j = c - k + 1; j <= c + k - 1; j++)
		{
			if (abs(i - r) + abs(j - c) < k)
			{
				if (i >= 0 && j >= 0 && i < N&& j < N && map[i][j] == 1)
				{
					profit += M;
				}
			}
		}
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
		cin >> N >> M;
		map.assign(N, vector<int>(N, 0));;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}

	}

	return 0;
}