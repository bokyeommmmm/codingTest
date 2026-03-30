#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, res;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
vector<vector<int>> board;
vector<vector<int>> visited;
queue<pair<int, int>>q;

void bfs()
{
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (visited[nr][nc] !=-1 ) //가봤으면패스
				continue;
			if (board[nr][nc] != board[r][c])
				continue;
			visited[nr][nc] = visited[r][c] + 1;
			res = max(res, visited[nr][nc]);
			q.push({ nr,nc });
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
			char c;
			cin >> c;
			if (c == 'L')
				board[i][j] = 0;
			else
				board[i][j] = -1;

		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] != -1)
			{
				visited.assign(N, vector<int>(M, -1));
				visited[i][j] = 0;
				q.push({ i,j });
				bfs();
			}
		}
	}
	cout << res;
	return 0;
}