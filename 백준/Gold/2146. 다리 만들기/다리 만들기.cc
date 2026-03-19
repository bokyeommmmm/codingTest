#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int N, res;


int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

vector<vector<int>>board;
vector<vector<int>>visited;

queue<pair<int, int>> q;


void bfs(int idx)
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
			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (visited[nr][nc] != -1)
				continue;
			if (board[nr][nc] == 0)
				continue;
			visited[nr][nc] = visited[r][c] + 1;
			board[nr][nc] = idx;
			q.push({ nr,nc });
		}
	}
}
// idx번 섬에서 다른 섬까지 최단 다리 찾기
void bridge(int idx)
{
	vector<vector<int>> dist(N, vector<int>(N, -1));
	queue<pair<int, int>> tempQ;

	// idx번 섬의 모든 칸을 시작점으로 넣음
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == idx)
			{
				tempQ.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	while (!tempQ.empty())
	{
		int r = tempQ.front().first;
		int c = tempQ.front().second;
		tempQ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;

			// 다른 섬에 닿으면 현재까지 바다 건넌 거리
			if (board[nr][nc] != 0 && board[nr][nc] != idx)
			{
				res = min(res, dist[r][c]);
				return;
			}

			// 바다만 확장
			if (board[nr][nc] == 0 && dist[nr][nc] == -1)
			{
				dist[nr][nc] = dist[r][c] + 1;
				tempQ.push({ nr,nc });
			}
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);


	cin >> N;
	board.assign(N, vector<int>(N, 0));
	visited.assign(N, vector<int>(N, -1));
	res = 10000;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>board[i][j];
		}
	}
	int idx = 1;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] != 0&&visited[i][j]==-1)
			{
				visited[i][j] = 1;
				board[i][j] = idx;
				q.push({ i,j });
				bfs(idx);
				idx++;
			}
		}
	}
	// 2. 각 섬마다 최단 다리 구하기
	for (int i = 1; i < idx; i++)
	{
		bridge(i);
	}

	cout << res << "\n";

	return 0;
}