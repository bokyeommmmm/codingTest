#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, res;
vector<vector<int>>board(19, vector<int>(19));
bool done = false;

void row(int r, int c, int cur)
{
	for (int i = -2; i <= 2; i++)
	{
		if (board[r + i][c] != cur)
			return;
	}
	cout << cur << "\n" << r + 1 << " " << c + 1;
	done = true;
	return;
}
void col(int r, int c, int cur)
{
	for (int i = -2; i <= 2; i++)
	{
		if (board[r][c + i] != cur)
			return;
	}
	cout << cur << "\n" << r + 1 << " " << c + 1;
	done = true;
	return;
}
void dia(int r, int c, int cur)
{
	for (int i = -2; i <= 2; i++)
	{
		if (board[r + i][c + i] != cur)
			return;
	}
	cout << cur << "\n" << r + 1 << " " << c + 1;
	done = true;
	return;

}
void dia2(int r, int c, int cur)
{
	for (int i = -2; i <= 2; i++)
	{
		if (board[r - i][c + i] != cur)
			return;
	}
	cout << cur << "\n" << r + 1 << " " << c + 1;
	done = true;
	return;

}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 19; i++)
	{
		for (int j = 0; j < 19; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 2; i < 17; i++)
		for (int j = 2; j < 17; j++)
		{
			if (done == false && board[i][j] != 0)
			{
				int cur = board[i][j];
				row(i, j, cur);
				col(i, j, cur);
				dia(i, j, cur);
				dia2(i, j, cur);
			}
		}
	if (done == false)
		cout << 0;
	return 0;
}