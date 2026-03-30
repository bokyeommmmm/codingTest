#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, leftcheese, timee;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
vector<vector<int>> board;

void melt()
{
	while (true)
	{
		int prevcheese = leftcheese;

		vector<vector<int>> air(N, vector<int>(M, 0));
		queue<pair<int, int>> q;
		q.push({ 0,0 });
		air[0][0] = 1;

		while (!q.empty())
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();

			for (int d = 0; d < 4; d++)
			{
				int nr = r + dr[d];
				int nc = c + dc[d];

				if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
				if (air[nr][nc]) continue;
				if (board[nr][nc] == 1) continue;

				air[nr][nc] = 1;
				q.push({ nr,nc });
			}
		}

		auto temp = board;
		timee++;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (board[i][j] == 1)
				{
					for (int d = 0; d < 4; d++)
					{
						int nr = i + dr[d];
						int nc = j + dc[d];

						if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;

						if (air[nr][nc])
						{
							temp[i][j] = 0;
							leftcheese--;
							break;
						}
					}
				}
			}
		}

		board = temp;

		if (leftcheese == 0)
		{
			leftcheese = prevcheese;
			return;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	board.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
				leftcheese++;
		}
	}

	if (leftcheese > 0)
		melt();

	cout << timee << "\n" << leftcheese;
	return 0;
}