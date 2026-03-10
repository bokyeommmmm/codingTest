#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M, FROM, TO;
vector<vector<int>> graph;
queue<int>q;
vector<int>visited;

void bfs()
{
	while (!q.empty())
	{
		int from = q.front();
		q.pop();
		if (from == TO)
			return;
		for (int i = 0; i < graph[from].size(); i++)
		{
			int to = graph[from][i];
			if (visited[to] != -1)
				continue;
			visited[to] = visited[from] + 1;
			q.push(to);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	cin >> FROM >> TO;
	cin >> M;
	graph.assign(N + 1, vector<int>(0));
	visited.assign(N + 1, -1);
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}
	visited[FROM] = 0;
	q.push(FROM);
	bfs();

	cout << visited[TO];
	return 0;
}