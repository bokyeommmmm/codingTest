#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, K;
int res;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
vector<vector<int>>map;
vector<vector<int>>visited;
void dfs(int r, int c, bool a, int len)
{
	res = max(len, res);
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= N || nc >= N)
			continue;
		if (map[nr][nc] >= map[r][c] && (a == true))
			continue;
		if (visited[nr][nc] == 1)
			continue;
		if (map[nr][nc] >= map[r][c] && (a == false) && map[nr][nc] - K < map[r][c]) //아직 안깎았고 깎아서 갈 높이면
		{

			int temp = map[nr][nc];
			map[nr][nc] = map[r][c] - 1;
			visited[nr][nc] = 1;
			dfs(nr, nc, true, len + 1);
			map[nr][nc] = temp;
			visited[nr][nc] = 0;

		}
		if (map[nr][nc] < map[r][c])
		{
			visited[nr][nc] = 1;
			dfs(nr, nc, a, len + 1);
			visited[nr][nc] = 0;

		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		int maxh = 0;
		cin >> N >> K;
		map.assign(N, vector<int>(N, 0));
		visited.assign(N, vector<int>(N, 0));

		res = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int temp;
				cin >> temp;
				map[i][j] = temp;
				maxh = max(temp, maxh);
			}
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][j] == maxh)
				{
					visited[i][j] = 1;
					dfs(i, j, false, 1);
					visited[i][j] = 0;
				}
			}
		}


		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}