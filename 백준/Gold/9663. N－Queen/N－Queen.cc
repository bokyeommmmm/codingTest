#include <iostream>
#include <vector>
using namespace std;

int N, res;
vector<vector<int>>board;

bool check(int r, int c)
{
	if (r == N)
		return true;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += board[i][c];
	}
	int nr = r;
	int nc = c;
	while (true)
	{
		nr -= 1;
		nc += 1;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)
			break;
		sum += board[nr][nc];
	}
	nr = r;
	nc = c;
	while (true)
	{
		nr -= 1;
		nc -= 1;
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)
			break;
		sum += board[nr][nc];
	}
	if (sum == 1)
		return true;
	else
		return false;
}

void dfs(int row)
{
	if (row == N )
	{
		res++;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		board[row][i] = 1;
		if (check(row, i) == true) //해당 칸 놓을 수 있으면 ㄱ
		{
			dfs(row + 1);
		}
		board[row][i] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	board.assign(N, vector<int>(N, 0));
	dfs(0);
	cout << res;
	return 0;
}