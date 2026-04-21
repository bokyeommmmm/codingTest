#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board(19, vector<int>(19));

bool row(int r, int c, int cur)
{
	for (int i = -2; i <= 2; i++) {
		if (board[r + i][c] != cur)
			return false;
	}
	return true;
}

bool col(int r, int c, int cur)
{
	for (int i = -2; i <= 2; i++) {
		if (board[r][c + i] != cur)
			return false;
	}
	return true;
}

bool dia(int r, int c, int cur)
{
	for (int i = -2; i <= 2; i++) {
		if (board[r + i][c + i] != cur)
			return false;
	}
	return true;
}

bool dia2(int r, int c, int cur)
{
	for (int i = -2; i <= 2; i++) {
		if (board[r - i][c + i] != cur)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 2; i < 17; i++) {
		for (int j = 2; j < 17; j++) {
			if (board[i][j] == 0) continue;

			int cur = board[i][j];

			if (row(i, j, cur) || col(i, j, cur) || dia(i, j, cur) || dia2(i, j, cur)) {
				cout << cur << "\n" << i + 1 << " " << j + 1;
				return 0;
			}
		}
	}

	cout << 0;
	return 0;
}