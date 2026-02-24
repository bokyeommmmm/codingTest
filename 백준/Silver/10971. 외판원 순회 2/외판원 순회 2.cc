#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N;
int res = 100000000;
vector<vector<int>>W;
vector<int>visited;

void dfs(int start, int from,int cnt,int cost)
{
	if (cost >= res) return;
	if (cnt == N - 1) 
	{
		if (W[from][start] == 0) return; 
		res = min(res, cost + W[from][start]);
		return;
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 1) continue;
		if (W[from][i] == 0) continue;

		visited[i] = 1;
		dfs(start, i, cnt + 1, cost + W[from][i]);
		visited[i] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	W.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin>>W[i][j];
		}
	}

	for (int i = 0; i < N; i++)
	{
		visited.assign(N, 0);
		visited[i] = 1;
		dfs(i,i,0,0);
	}
	cout << res;
	return 0;
}