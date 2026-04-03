#include <iostream>
#include <vector>
#include <string>
#include<queue>

using namespace std;

int T, W, H;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

vector<vector<char>>board;
vector<vector<int>>visited;
queue<pair<int, int>>q;
vector<vector<int>>dist;
void bfs() //불 퍼지는 시간 끝. 
{
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int  i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= H || nc >= W)
				continue;
			if(board[nr][nc]=='#')
				continue;
			if(visited[nr][nc]!=-1)
				continue;
			visited[nr][nc] = visited[r][c] + 1;
			q.push({ nr,nc });
		}
	}

}
void bfs2() //탈출
{
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		int curTime = dist[r][c];
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= H || nc >= W)
			{
				cout << curTime + 1 << "\n";
				return;
			}
			if (board[nr][nc] == '#')
				continue;
			if (dist[nr][nc] != -1)
				continue;
			if(visited[nr][nc]!=-1 && visited[nr][nc] <= curTime+1)
				continue;

			dist[nr][nc] = curTime + 1;
			q.push({ nr,nc });
		}
	}
	cout <<"IMPOSSIBLE\n";
	return;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> W >> H;
		board.assign(H, vector<char>(W, '\0'));
		visited.assign(H, vector<int>(W, -1));
		dist.assign(H, vector<int>(W, -1));
		while (!q.empty())
		{
			q.pop();
		}
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				char c;
				cin >> c;
				board[i][j] = c;
				
				if (c == '*')
				{
					visited[i][j] = 0;
					q.push({ i,j });
				}
			}
		}
		bfs();

		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				if (board[i][j] == '@')
				{
					dist[i][j] = 0;
					q.push({ i,j });
				}
			}
		}
		bfs2();
	}


	return 0;
}