#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, res, SIZE, maxDist; //SIZE : 후보 갯수 
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
bool isAllCover;
vector<vector<int>>board;
vector<pair<int, int>> candidate;
vector<int>input;
queue<pair<int, int>>q;

void bfs()
{
	vector<vector<int>>dist(N, vector<int>(N, -1));

	for (int i = 0; i < M; i++)
	{
		int idx = input[i];
		int r = candidate[idx].first;
		int c = candidate[idx].second;
		dist[r][c] = 0;
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
			if (nr < 0 || nc < 0 || nr >= N || nc >= N) //범위 밖 패스
				continue;
			if (board[nr][nc] == 1) // 벽 패스 
				continue;
			if (dist[nr][nc] >= 0) //간 적 있으면 pass
				continue;
			if (board[nr][nc] == 2 || board[nr][nc] == 0) //빈칸이거나 바이러스이면 
			{
				dist[nr][nc] = dist[r][c] + 1;
				q.push({ nr,nc });
			}
		}
	}
	//일단 바이러스 퍼질대로 다 퍼지고 나서 .

	maxDist = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (board[i][j] == 0) //벽인데 
			{
				if (dist[i][j] >= 0) //퍼졌다면
					maxDist = max(maxDist, dist[i][j]); //빈칸중에 가장 늦게 간 것.
				else
					return;
			}
		}
	}
	isAllCover = true;
	res = min(res, maxDist);
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
	isAllCover = false;
	board.assign(N, vector<int>(N, 0));
	res = 3000;
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

	if (isAllCover)
		cout << res;
	else
		cout << -1;

	return 0;
}
