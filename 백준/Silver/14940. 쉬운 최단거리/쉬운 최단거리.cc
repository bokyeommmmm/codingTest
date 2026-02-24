#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int N, M;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
vector<vector<int>>map;
vector<vector<int>>visited;
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
			if (map[nr][nc] == 0)
			{
				visited[nr][nc] = 1;
				continue;
			}
			if (visited[nr][nc] == 1)
				continue;
			map[nr][nc] = map[r][c] + 1;
			visited[nr][nc] = 1;
			q.push({ nr,nc });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	map.assign(N, vector<int>(M, 0));
	visited.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			int temp;
			cin >> temp;

			map[i][j] = temp;
			if (temp == 2)
			{
				map[i][j] = 0;
				visited[i][j] = 1;
				q.push({ i,j });
			}
		}
	}

	bfs();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visited[i][j] == 0&&map[i][j]==1)
				map[i][j] = -1;
			cout << map[i][j] << " ";
		}
		cout << "\n";
	}
	return 0;
}