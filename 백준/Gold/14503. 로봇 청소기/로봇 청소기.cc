#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, res;
int dr[4] = {-1,0,1,0}; //북 동 남 서
int dc[4] = {0,1,0,-1};
int r, c, d;
vector<vector<int>>map;
void func()
{
	if (map[r][c] == 0)
	{
		map[r][c] = 2;
		res++;
	}
	int k = 0;
	for (int i = 0; i < 4; i++)
	{
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || nc < 0 || nr >= N ||nc>= M)
			continue;
		if (map[nr][nc] == 0)
			k++;
	}
	if (k == 0)
	{
		int backDir = (d + 2) % 4;   // 
		int nr = r + dr[backDir];
		int nc = c + dc[backDir];

		if (nr < 0 || nc < 0 || nr >= N || nc >= M) return;

		if (map[nr][nc] == 1) return;

		r = nr; c = nc;
		func();
		return;
	}
	else if (k > 0)
	{
		d = (d + 3)%4;
		int nr = r + dr[d];
		int nc = c + dc[d];
		if (nr >= 0 && nc >= 0 && nr < N && nc < M && map[nr][nc] == 0)
		{
			r = nr;
			c = nc;
		}
		func();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> N >> M;
	cin >> r >> c >> d;
	map.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}
	func();
	cout << res;
	return 0;
}