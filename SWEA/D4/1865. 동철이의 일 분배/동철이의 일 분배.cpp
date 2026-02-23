#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int N;
vector<vector<double>> board;
vector<int> used;

double res;   
double prob;  

void dfs(int cnt)
{

	if (prob <= res) return;

	if (cnt == N)
	{
		res = max(res, prob);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (used[i] == 1) continue;
		if (board[i][cnt] == 0.0) continue; 

		used[i] = 1;

		double prev = prob;
		prob *= (board[i][cnt] / 100.0);

		dfs(cnt + 1);

		prob = prev;
		used[i] = 0;
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
		cin >> N;
		board.assign(N, vector<double>(N, 0.0));
		used.assign(N, 0);

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> board[i][j];
			}
		}

		res = 0.0;
		prob = 100.0;

		dfs(0);

		cout << "#" << tc << " " << fixed << setprecision(6) << res << "\n";
	}

	return 0;
}