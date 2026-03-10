#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, M, white, blue;
vector<vector<char>>board;
vector<vector<int>>visited;
queue<pair<int, int>>q;

int dr[4] = { 0,0,1,-1, };
int dc[4] = { 1,-1,0,0 };

void bfs(char ch)
{
	int area = 0;
	while (!q.empty())
	{
		area++;
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (visited[nr][nc] == 1)
				continue;
			if (board[nr][nc] == ch)
			{
				visited[nr][nc] = 1;
				q.push({ nr,nc });
			}
		}
	}
	int power = area * area;
	if (ch == 'W')
	{
		white += power;
	}
	else
		blue += power;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> M >> N;
	board.assign(N, vector<char>(M, '\0'));
	visited.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0)
			{
				q.push({ i,j });
				visited[i][j] = 1;
				bfs(board[i][j]);
			}
		}
	}
	cout << white << " " << blue;
	return 0;
}