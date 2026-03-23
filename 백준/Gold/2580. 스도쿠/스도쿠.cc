#include<iostream>
#include<vector>
using namespace std;


int board[9][9];
int visited[10];
bool done = false;
bool check(int r, int c)
{
	for (int i = 1; i <= 9; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < 9; i++)
	{
		if (board[i][c]!=0&&visited[board[i][c]] == 0)
			visited[board[i][c]] = 1;
		else if(board[i][c]!= 0 && visited[board[i][c]] == 1)
			return false;
	}
	for (int i = 1; i <= 9; i++)
	{
		visited[i] = 0;
	}
	for (int i = 0; i < 9; i++)
	{
 		if (board[r][i] != 0 && visited[board[r][i]] == 0)
			visited[board[r][i]] = 1;
		else if (board[r][i] != 0 && visited[board[r][i]] == 1)
			return false;
	}
	for (int i = 1; i <= 9; i++)
	{
		visited[i] = 0;
	}
	for (int i = (r / 3) * 3; i < (r / 3) * 3 + 3; i++)
	{
		for (int j = (c / 3) * 3; j < (c / 3) * 3 + 3; j++)
		{
			if (board[i][j] != 0 && visited[board[i][j]] == 0)
				visited[board[i][j]] = 1;
			else if (board[i][j] != 0 && visited[board[i][j]] == 1)
				return false;
		}
	}
	return true;
}

void dfs()
{
	if (done == true)
		return;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				for (int k = 1; k <= 9; k++)
				{
					board[i][j] = k;
					if (check(i, j) == true)
					{
						dfs();
						if (done == true)
							return;
					}
					board[i][j] = 0;
				}
				return; // 얘가 머임 
			}
		}
	}
	if (done == true)
		return;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	done = true;

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> board[i][j];
		}
	}

	dfs();

	return 0;
}