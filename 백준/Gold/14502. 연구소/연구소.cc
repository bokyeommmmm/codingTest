#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> map;
vector<vector<int>> visited;
queue<pair<int, int>> q;
int res = 0;
int N, M;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void calc(vector<vector<int>> &temp_map) {
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (temp_map[i][j] == 0)
				sum++;
		}
	}
	res = max(res, sum);
}
void bfs() // 바이러스 ㄱㄱ;
{
	auto temp_map = map;
	auto temp_q = q;
	auto temp_visited = visited;
	while (!temp_q.empty())
	{
		int r = temp_q.front().first;
		int c = temp_q.front().second;
		temp_q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (temp_visited[nr][nc] == 1)
				continue;
			if (temp_map[nr][nc] == 1)
				continue;
			temp_visited[nr][nc] = 1;
			temp_map[nr][nc] = 2;
			temp_q.push({ nr,nc });
		}
	}
	calc(temp_map);
}

void make_wall(int cnt)
{
	if (cnt == 3)
	{
		bfs();
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 1 || map[i][j] == 2) // 벽이나 바이러스면 x
				continue;
			map[i][j] = 1;
			make_wall(cnt + 1);
			map[i][j] = 0;
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
	int temp; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> temp;
			map[i][j] = temp;
			if (temp == 2)
			{
				visited[i][j] = 1;
				q.push({ i, j });
			}
		}
	}

	make_wall(0);

	cout << res;
	return 0;
}