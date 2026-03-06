#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int V, E, done;
vector<vector<int>>graph;
vector<vector<int>>required;
vector<int>path;
vector<int>visited;
queue<int>q;

bool canGo(int to)
{
	for (int i = 0; i < required[to].size(); i++)
	{
		int from = required[to][i];
		if (visited[from] == 0)
			return false;
	}
	return true;
}

void bfs()
{
	while (!q.empty())
	{
		int from = q.front();
		q.pop();
		if (done == V)
			return;
		for (int i = 0; i < graph[from].size(); i++)
		{
			int to = graph[from][i];
			if (visited[to] == 1)
				continue;
			if (!canGo(to))
				continue;
			visited[to] = 1;
			path.push_back(to);
			done++;
			q.push(to);

		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	T = 10;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> V >> E;
		graph.assign(V + 1, vector<int>(0));
		required.assign(V + 1, vector<int>(0));
		path.clear();
		visited.assign(V + 1, 0);
		done = 0;

		while (!q.empty())
			q.pop();
		for (int i = 0; i < E; i++)
		{
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			required[to].push_back(from);
		}
		for (int i = 1; i <= V; i++)
		{
			if (required[i].size() == 0)//선행작업 없으면
			{
				visited[i] = 1;
				done++;
				path.push_back(i);
				q.push(i);
			}
		}
		bfs();

		cout << "#" << tc << " ";
		for (int i = 0; i < V; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
	}

	return 0;
}