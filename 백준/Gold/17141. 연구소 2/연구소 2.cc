#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, res, SIZE; //SIZE : 후보 갯수 
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
vector<vector<int>>board;
vector<pair<int, int>> candidate;
vector<int>input; 
queue<pair<int, int>>q;

void bfs()
{
	auto temp = board;
	int Min = 0;
	for (int i = 0; i < M; i++)
	{
		int idx = input[i];
		int r = candidate[idx].first;
		int c = candidate[idx].second;
		temp[r][c] = -1;
		q.push({ r,c });
	}
	
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
			if (temp[nr][nc] == 1)
				continue;
			if (temp[nr][nc] == 2 || temp[nr][nc] == 0)
			{
				temp[nr][nc] = temp[r][c] - 1;
				Min = min(Min, temp[nr][nc]);
				q.push({ nr,nc });
			}
		}


	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (temp[i][j] == 0||temp[i][j]==2)
				return;
		}
	}
	if (Min == 0) res = min(res, 0);
	else res = min(res, abs(Min) - 1);
}

void dfs(int idx, int cnt)
{
	if (idx == SIZE) {
		if (cnt == M)
		{
			bfs();
		}
		return;
	}
	input.push_back(idx);
	dfs(idx + 1, cnt + 1);
	input.pop_back();
	dfs(idx + 1, cnt);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	board.assign(N, vector<int>(N, 0));
	res = 1000;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int temp;
			cin >> temp;
			board[i][j] = temp;
			if (temp == 2)
			{
				candidate.push_back({ i,j });
				SIZE++;
			}
		}
	}
	dfs(0, 0);
	if (res == 1000)
		res = -1;
	cout << res;
	return 0;
}