#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, M;
vector<vector<int>> graph;
vector<int>visited;
vector<int>path;
queue<int> q;
void init()
{
	cin >> N >> M;
	graph.assign(N + 1, vector<int>(0));
	visited.assign(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int temp;
			cin >> temp;
			if (temp == 1)
				graph[i].push_back(j);
		}
	}
	for (int i = 0; i < M; i++)
	{
		int a;
		cin >> a;
		path.push_back(a);
	}
}
void bfs()
{
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i];
			if (visited[next] == 0)
			{
				visited[next] = 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	q.push(path[0]);
	visited[path[0]] = 1;
	bfs();

	for (int i = 0; i < M; i++)
	{
		if (visited[path[i]] == 0)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}