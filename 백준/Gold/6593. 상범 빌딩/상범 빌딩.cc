#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int L, R, C;

int dl[6] = { 1,-1,0,0,0,0 };
int dr[6] = { 0,0,1,-1,0,0 };
int dc[6] = { 0,0,0,0,1,-1 };

vector<vector<vector<char>>>building;
vector<vector<vector<int>>>visited;
struct lrc
{
	int l;
	int r;
	int c;
};

queue<lrc> q;


void bfs()
{
	while (!q.empty())
	{
		int l = q.front().l;
		int r = q.front().r;
		int c = q.front().c;
		q.pop();
		if (building[l][r][c] == 'E')
		{
			cout << "Escaped in " << visited[l][r][c] << " minute(s).\n";
			return;
		}
		for (int i = 0; i < 6; i++)
		{
			int nl = l + dl[i];
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nl < 0 || nr < 0 || nc < 0 || nl >= L || nr >= R || nc >= C)
				continue;
			if (visited[nl][nr][nc] != -1)
				continue;
			if (building[nl][nr][nc] == '#')
				continue;
			visited[nl][nr][nc] = visited[l][r][c] + 1;
			q.push({ nl,nr,nc });
		}
	}
	cout << "Trapped!\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			return 0;
		building.assign(L, vector<vector<char>>(R, vector<char>(C, 0)));
		visited.assign(L, vector<vector<int>>(R, vector<int>(C, -1)));
		while (!q.empty())
		{
			q.pop();	
		}
		for (int l = 0; l < L; l++)
		{
			for (int r = 0; r < R; r++)
			{
				for (int c = 0; c < C; c++)
				{
					char ch;
					cin >> ch;
					building[l][r][c] = ch;
					if (ch == 'S')
					{
						visited[l][r][c] = 0;
						q.push({ l,r,c });
					}
				}
			}
		}
		bfs();
	}
	return 0;
}