#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int K, V, E;
vector<vector<int>> graph;
vector<int> visited;

bool bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = 1;

	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		for (int i = 0; i < graph[now].size(); i++)
		{
			int next = graph[now][i];

			// 아직 방문 안 했으면 반대 팀
			if (visited[next] == 0)
			{
				visited[next] = -visited[now];
				q.push(next);
			}
			// 이미 방문했는데 같은 팀 : false
			else if (visited[next] == visited[now])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		cin >> V >> E;

		graph.assign(V + 1, vector<int>());
		visited.assign(V + 1, 0);

		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		bool flag = true;

		for (int i = 1; i <= V; i++)
		{
			if (visited[i] == 0)
			{
				if (!bfs(i))
				{
					flag = false;
					break;
				}
			}
		}

		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}