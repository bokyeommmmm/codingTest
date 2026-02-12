#include<iostream>
#include<vector>
#include<set>
using namespace std;

int N, M, R, C, L, res;
int dr[4] = { -1,1,0,0 }; //상 하 좌 우 
int dc[4] = { 0,0,-1,1 };
vector<vector<int>>board;
vector<vector<int>>visited;
set<pair<int, int>>s;

void dfs(int r, int c, int cnt) {
	s.insert({ r,c });
	if (cnt == L)
	{
		return;
	}
	int temp = board[r][c];
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= N || nc >= M)
			continue;
		if (board[nr][nc]==0)
			continue;
		if (visited[nr][nc] != 0 && visited[nr][nc] <= cnt + 1)
			continue;
		int next = board[nr][nc];
		if (i == 0 && (temp == 1 || temp == 2 || temp == 4 || temp == 7) && (next == 1 || next == 2 || next == 5 || next == 6))
		{
			visited[nr][nc] = cnt+1;
			dfs(nr, nc, cnt + 1);
		}
		else if (i == 1 && (temp == 1 || temp == 2 || temp == 5 || temp == 6) && (next == 1 || next == 2 || next == 4 || next == 7))
		{
			visited[nr][nc] = cnt + 1;
			dfs(nr, nc, cnt + 1);
		}
		else if (i == 2 && (temp == 1 || temp == 3 || temp == 6 || temp == 7) && (next == 1 || next == 3 || next == 4 || next == 5))
		{
			visited[nr][nc] = cnt + 1;
			dfs(nr, nc, cnt + 1);
		}
		else if (i == 3 && (temp == 1 || temp == 3 || temp == 4 || temp == 5) && (next == 1 || next == 3 || next == 6 || next == 7))
		{
			visited[nr][nc] = cnt + 1;
			dfs(nr, nc, cnt + 1);
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
		cin >> N >> M >> R >> C >> L;
		res = 0;
		s.clear();
		board.assign(N, vector<int>(M, 0));
		visited.assign(N, vector<int>(M, 0));

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				cin >> board[i][j];
			}
		}
		visited[R][C] = 1;
		dfs(R, C, 1);
		res = s.size();
		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}