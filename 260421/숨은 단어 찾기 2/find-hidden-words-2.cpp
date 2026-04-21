#include <iostream>
#include <vector>
#include<string>
using namespace std;

int N, M, res;
vector<string> board;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		board.push_back(str);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M - 2; j++)
		{
			if (board[i][j] == 'L'&&board[i][j + 1] == 'E'&&board[i][j + 2] == 'E')
				res++;
			if (board[i][j] == 'E'&&board[i][j + 1] == 'E'&&board[i][j + 2] == 'L')
				res++;

		}
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] == 'L'&&board[i + 1][j] == 'E'&&board[i + 2][j] == 'E')
				res++;
			if (board[i][j] == 'E'&&board[i + 1][j] == 'E'&&board[i + 2][j] == 'L')
				res++;
		}
	}
	for (int i = 2; i < N; i++)
	{
		for (int j = 0; j < M-2; j++)
		{
			if (board[i][j] == 'L'&&board[i - 1][j+1] == 'E'&&board[i - 2][j+2] == 'E')
				res++;
			if (board[i][j] == 'E'&&board[i - 1][j + 1] == 'E'&&board[i - 2][j + 2] == 'L')
				res++;
		}
	}
	for (int i = 0; i < N-2; i++)
	{
		for (int j = 0; j < N-2; j++)
		{
			if (board[i][j] == 'L'&&board[i + 1][j + 1] == 'E'&&board[i + 2][j + 2] == 'E')
				res++;
			if (board[i][j] == 'E'&&board[i + 1][j + 1] == 'E'&&board[i + 2][j + 2] == 'L')
				res++;
		}
	}

	cout << res;
	return 0;
}