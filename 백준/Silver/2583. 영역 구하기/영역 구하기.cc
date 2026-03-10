#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, K, area;
vector<vector<int>> board;
queue<pair<int, int>>q;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0 ,0 };
vector<int>res;
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

			if (nr<0 || nc<0 || nr>=N || nc>=M)
				continue;
			if (board[nr][nc] == 0)
			{
				area++;
				board[nr][nc] = 2;
				q.push({ nr,nc });
			}
		}
	}
	res.push_back(area);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> K;

	board.assign(N, vector<int>(M, 0));

	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int x = x1; x < x2; x++)
		{
			for (int y = y1; y < y2; y++)
			{
				board[x][y] = 1;
			}
		}
	}

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (board[i][j] == 0)
			{
				area = 1;
				board[i][j] = 2;
				q.push({ i,j });
				bfs();
			}
		}
	}
	
	sort(res.begin(), res.end());
	cout << res.size()  << "\n";
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}