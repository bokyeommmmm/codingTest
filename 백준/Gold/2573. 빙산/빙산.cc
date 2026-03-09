#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int N, M, res;
bool done = false;
vector<vector<int>>board;
vector<vector<int>>visited;
queue<pair<int, int>>q;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

void melt()
{
	vector<vector<int>> meltamt(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] > 0)
			{
				int cnt = 0;
				for (int d	 = 0; d < 4; d++)
				{
					int nr = i + dr[d];
					int nc = j + dc[d];
					if (nr < 0 || nc < 0 || nr >= N || nc >= M)
						continue;
					if (board[nr][nc] <= 0)
						cnt++;
				}
				meltamt[i][j] = cnt;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			board[i][j] = board[i][j] - meltamt[i][j];
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

		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= N || nc >= M)
				continue;
			if (visited[nr][nc] == 1)
				continue;
			if (board[nr][nc] <= 0)
				continue;
			visited[nr][nc] = 1;
			q.push({ nr,nc });
		}
	}
}

bool isDivided()
{
	visited.assign(N, vector<int>(M, 0));
	int land = 0;
	while (!q.empty())
	{
		q.pop();
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <M ; j++)
		{
			if (board[i][j] > 0&&visited[i][j]==0)
			{
				if (land == 1)
				{
					done = true;
					return true;
				}
				land++;
				visited[i][j] = 1;
				q.push({ i,j });
				bfs();
			}
		}
	}
	return false;
}
bool func()
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (board[i][j] > 0)
				return true;
		}
	}
	return false;
}
int simul()
{
	int year = 0;
	while (true)
	{
		if (isDivided())
			return year;
		year++;
		melt();
		if (!func())
			break;
	}
	return year;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	board.assign(N, vector<int>(M));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> board[i][j];
		}
	}
	int res = simul();
	if (done == true)
		cout << res;
	else
		cout << 0;
	return 0;
}