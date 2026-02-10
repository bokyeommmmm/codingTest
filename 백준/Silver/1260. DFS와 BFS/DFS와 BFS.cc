#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

int N, M, V;
vector<vector<int>> graph;
vector<int>visited;

queue<int>q;

void dfs(int V) {

	cout << V << " ";
	for (int i = 0; i < graph[V].size(); i++)
	{
		int next = graph[V][i];
		if (visited[next] == 1)
			continue;
		visited[next] = 1;
		dfs(next);
	}
}
void bfs(int V)
{	
	while (!q.empty())
	{
		V = q.front();
		cout << V << " ";
		q.pop();
		for (int i = 0; i < graph[V].size(); i++)
		{
			int next = graph[V][i];
			if (visited[next] == 1)
				continue;
			visited[next] = 1;
			q.push(next);
		}

	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> V;

	graph.assign(N + 1, vector<int>(0));

	int from, to;
	for (int i = 0; i < M; i++)
	{
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= N; i++)
	{
		sort(graph[i].begin(), graph[i].end());
	}
	visited.assign(N + 1, 0);
	visited[V] = 1;
	dfs(V);
	cout << "\n";
	visited.assign(N + 1, 0);
	q.push(V);
	visited[V] = 1;
	bfs(V);
	return 0;
}