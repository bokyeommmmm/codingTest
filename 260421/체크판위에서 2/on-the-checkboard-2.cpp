#include <iostream>
#include <vector>

using namespace std;

int R, C, res;
vector<vector<char>> board;

void func(int r, int c, int cnt)
{
	if (r == R - 1 && c == C - 1)
	{
		if (cnt == 2) {
			res++;
		}
		return;
	}

	if (cnt > 2) return;

	for (int i = r + 1; i < R; i++)
	{
		for (int j = c + 1; j < C; j++)
		{
			if (board[i][j] != board[r][c])
			{
				if (i == R - 1 && j == C - 1) {
					func(i, j, cnt);
				}
				else {
					func(i, j, cnt + 1);
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C;

	board.assign(R, vector<char>(C));
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> board[i][j];
		}
	}

	func(0, 0, 0);

	cout << res;
	return 0;
}