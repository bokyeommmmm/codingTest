#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int D, W, K;
int res;
vector<vector<int>> cell;
vector<int>A;
vector<int>B;
bool test()
{
	for (int j = 0; j < W; j++)
	{
		int cnt = 1;
		bool ok = false;

		for (int i = 1; i < D; i++)
		{
			if (cell[i][j] == cell[i - 1][j])
				cnt++;
			else
				cnt = 1;

			if (cnt >= K)
			{
				ok = true;
				break;
			}
		}

		if (K == 1) ok = true;

		if (!ok) return false;
	}
	return true;
}

void dfs(int idx, int cnt)
{
	if (cnt >= res) return;
	if (test())
	{
		res = min(res, cnt);
		return;
	}
	if (idx == D)
		return;
	dfs(idx + 1, cnt);
	auto temp = cell[idx];
	cell[idx] = A;
	dfs(idx + 1, cnt + 1);
	cell[idx] = B;
	dfs(idx + 1, cnt + 1);
	cell[idx] = temp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> D >> W >> K;

		cell.assign(D, vector<int>(W, 0));
		A.assign(W, 0);
		B.assign(W, 1);
		res = 100;
		for (int i = 0; i < D; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> cell[i][j];
			}
		}
		if (test() != true) //첨에 통과가 아니면 약품넣자잉
			dfs(0, 0);
		else
			res = 0;

		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}