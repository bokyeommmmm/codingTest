#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int T, N;
vector<vector<int>> board;
vector<vector<int>> dist;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };

void dijkstra()
{
	priority_queue < pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
	dist[0][0] = 0;
	pq.push({ 0,{0,0} });
	while (!pq.empty())
	{
		int r = pq.top().second.first;
		int c = pq.top().second.second;
		int nowCost = pq.top().first;
		pq.pop();
		if (dist[r][c] < nowCost)
			continue;
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nc < 0 || nr >= N || nc >= N)
				continue;
			if (dist[nr][nc] <= dist[r][c] + board[nr][nc])
				continue;
			dist[nr][nc] = dist[r][c] + board[nr][nc];
			pq.push({ dist[nr][nc],{nr,nc} });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		board.assign(N, vector<int>(N));
		dist.assign(N, vector<int>(N, 200000000));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				char temp;
				cin >> temp;
				board[i][j] = temp - '0';
			}
		}

		dijkstra();

		cout << "#" << tc << " " << dist[N - 1][N - 1] << "\n";
	}

	return 0;
}