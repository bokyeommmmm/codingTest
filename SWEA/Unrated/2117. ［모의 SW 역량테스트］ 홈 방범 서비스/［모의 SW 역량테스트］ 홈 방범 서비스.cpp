#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<int>> map;
int profit;
int res;
int cnt;
void getServiceArea(int r, int c, int k) //마름모 완료
{
	profit = -((k*k) + (k - 1)*(k - 1));
	cnt = 0;
	for (int i = r - k + 1; i <= r + k - 1; i++)
	{
		for (int j = c - k + 1; j <= c + k - 1; j++)
		{
			if (abs(i - r) + abs(j - c) < k)
			{
				if (i >= 0 && j >= 0 && i < N&& j < N && map[i][j] == 1)//범위 안에 집이 있으면 집 갯수만큼 이득 
				{
					profit += M;
					cnt++;
				}
			}
		}
	}
	if (profit >= 0) {
		res = max(res, cnt);
	}
}

void func(int k)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			profit = 0;
			getServiceArea(i, j, k);
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
		map.assign(N, vector<int>(N, 0));
		res = 0;
		int temp;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> temp;
				map[i][j] = temp;

			}
		}
		for (int i = 1; i <= N+1; i++)
		{
			func(i);
		}
		cout << "#" << tc << " " << res << "\n";
	}

	return 0;
}