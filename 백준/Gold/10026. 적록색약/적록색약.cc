#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N, res;
vector<vector<char>>map;
vector<vector<int>>visited;
queue<pair<int, int>>q;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
void bfs1()
{
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		char color = map[r][c];
		for (int d = 0; d < 4; d++)
		{
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (visited[nr][nc] == 1)
				continue;
			if (color == 'R'&&map[nr][nc] == 'B')
				continue;
			if (color == 'G'&&map[nr][nc] == 'B')
				continue;
			if (color =='B'&& (map[nr][nc]=='R'||map[nr][nc]=='G'))
				continue;
			visited[nr][nc] = 1;
			q.push({ nr,nc });
		}
	}
}
void bfs()
{
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		char color = map[r][c];
		for (int d = 0; d < 4; d++)
		{
			int nr = r + dr[d];
			int nc = c + dc[d];
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (visited[nr][nc] == 1)
				continue;
			if (color != map[nr][nc])
				continue;
			visited[nr][nc] = 1;
			q.push({ nr,nc });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	map.assign(N, vector<char>(N, '\0'));
	visited.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)
			{
				visited[i][j] = 1;
				q.push({ i,j });
				res++;
				bfs();
			}
		}
	}
	while (!q.empty()) {
		q.pop();
	}
	cout << res << " ";
	visited.assign(N, vector<int>(N, 0));
	res = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visited[i][j] == 0)
			{
				visited[i][j] = 1;
				q.push({ i,j });
				res++;
				bfs1();
			}
		}
	}
	cout << res << " ";

	return 0;
}