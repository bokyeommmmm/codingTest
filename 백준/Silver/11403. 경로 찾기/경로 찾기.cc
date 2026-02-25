#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>>graph;
vector<int>visited;
queue<int>q;
int res = 1;
int score = 10000;

void bfs()
{
	while (!q.empty())
	{
		int  k = q.front();
		q.pop();
		for (int i = 0; i < graph[k].size(); i++)
		{
			int next = graph[k][i];
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
	cin >> N;
	graph.assign(N+1, vector<int>());

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
	for (int i = 1; i <= N; i++)
	{
		visited.assign(N + 1, 0);
		while (!q.empty())
		{
			q.pop();
		}
		q.push(i);
		bfs();
		for (int j = 1; j <= N; j++)
		{
			cout << visited[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}