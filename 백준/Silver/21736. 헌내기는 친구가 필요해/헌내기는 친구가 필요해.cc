#include <iostream>
#include <vector>
#include<string>
using namespace std;
int N, M, res;
int dr[4] = { 0,0,1,-1 };
int dc[4] = { 1,-1,0,0 };
vector<vector<char>> map;
vector<vector<int>> visited;
void dfs(int sr, int sc)
{
	if (map[sr][sc] == 'P')
		res++;
	for (int i = 0; i < 4; i++)
	{
		int nr = sr + dr[i];
		int nc = sc + dc[i];
		
		if (nr < 0 || nc < 0 || nr >= N || nc >= M)
			continue;
		if (map[nr][nc] == 'X')
			continue;
		if (visited[nr][nc] == 1)
			continue;
		visited[nr][nc] = 1;
		dfs(nr, nc);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	map.assign(N, vector<char>(M, '\0'));
	visited.assign(N, vector<int>(M, 0));
	int sr, sc;

	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < M; j++)
		{
			map[i][j] = str[j];
			if (str[j] == 'I')
			{
				sr = i;
				sc = j;
			}
		}
	}
	visited[sr][sc] = 1;
	dfs(sr,sc);

	if (res == 0)
	{
		cout << "TT";
	}
	else
	cout << res;
	return 0;
}