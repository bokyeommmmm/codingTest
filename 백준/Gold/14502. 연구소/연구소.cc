#include <iostream>
#include <vector>
#include<queue>
#include <algorithm>
using namespace std;

int N, M, res;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
vector<vector<int>>board;
vector<vector<int>>visited;
queue<pair<int, int>>q;

void bfs()
{
	auto qq = q;
	auto visit = visited;
	auto temp = board;
	while (!qq.empty())
	{
		int r = qq.front().first;
		int c = qq.front().second;
		qq.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (temp[nr][nc] == 1)
				continue;
			if (visit[nr][nc] == 1)
				continue;
			visit[nr][nc] = 1;
			temp[nr][nc] = 2;
			qq.push({ nr,nc });

		}
	}
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp[i][j] == 0)
				sum++;
		}
	}
	res = max(res, sum);

}

void dfs(int cnt, int start)
{
	if (cnt == 3)
	{
		bfs();
		return;
	}

	for (int i = start; i < N*M; i++)
	{
		int r = i / M;
		int c = i % M;
		if (board[r][c] == 0)
		{
			board[r][c] = 1;
			dfs(cnt + 1, i + 1);
			board[r][c] = 0;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	board.assign(N, vector<int>(M, 0));
	visited.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int t;
			cin >> t;
			board[i][j] = t;
			if (t == 2)
			{
				visited[i][j] = 1;
				q.push({ i,j });
			}
		}
	}
	dfs(0, 0);

	cout << res;
	return 0;
}
