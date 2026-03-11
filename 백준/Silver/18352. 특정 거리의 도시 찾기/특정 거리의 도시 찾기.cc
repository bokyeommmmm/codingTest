#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, K, X;
vector<vector<int>> graph;
vector<int>visited;
queue<int>q;

void bfs()
{
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];

			if (visited[next] != -1)
				continue;
			visited[next] = visited[cur]+1;
			q.push(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K >> X;
	graph.assign(N + 1,vector<int>(0));
	visited.assign(N + 1, -1);
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
	}
	visited[X] = 0;
	q.push(X);
	bfs();
	vector<int>res;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == K)
			res.push_back(i);
	}

	if (res.size() == 0)
	{
		cout << -1;
		return 0;
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "\n";
	}
	return 0;
}