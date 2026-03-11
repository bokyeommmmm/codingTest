#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, MAX;
vector<vector<int>> trust;
vector<int>visited;
queue<int>q;
vector<vector<int>>res;
int bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		cnt++;
		int cur = q.front();
		q.pop();
		for (int i = 0; i < trust[cur].size(); i++)
		{
			int next = trust[cur][i];
			if (visited[next] == 1)
				continue;
			visited[next] = 1;
			q.push(next);
		}
	}
	return cnt;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	trust.assign(N + 1, vector<int>(0));
	visited.assign(N + 1, 0);
	res.assign(N + 1, vector<int>(0)); //[i][] i대를 해킹할 수 있는 pc 번호들 

	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		trust[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		
		visited.assign(N + 1, 0);

		visited[i] = 1;
		q.push(i);
		int cnt = bfs();
		MAX = max(MAX, cnt);
		res[cnt].push_back(i);
	}

	for (int i = 0; i < res[MAX].size(); i++)
	{
		cout << res[MAX][i] << " ";
	}
	return 0;
}