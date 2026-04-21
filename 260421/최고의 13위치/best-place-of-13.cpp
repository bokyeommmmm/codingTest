#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int N, res;
vector<vector<int>>board;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	board.assign(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> board[i][j];
		}
	}

	int sum = 0;

	for (int i = 0; i < N ; i++)
	{
		for (int j = 0; j < N - 2; j++)
		{
			sum = 0;
			for (int k = 0; k < 3; k++)
			{
				sum += board[i][j + k];
			}
			res = max(res, sum);
			if (res == 3)
			{
				cout << 3;
				return 0;
			}
		}
	}

	cout << res;
	return 0;
}