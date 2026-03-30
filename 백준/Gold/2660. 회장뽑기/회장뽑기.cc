#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

int N, minscore;
vector<vector<int>> graph;
vector<int>visited;
vector<vector<int>>res;
queue<int> q;
void init()
{
	cin >> N;
	graph.assign(N + 1, vector<int>(0));
	res.assign(50,vector<int>(0));
	minscore = 2000000;
	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)
		{
			break;
		}
		graph[a].push_back(b);
		graph[b].push_back(a);
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
			if (visited[next] == -1)
			{
				visited[next] = visited[cur] + 1;
				q.push(next);
			}
		}
	}
}
void calc(int cur)
{
	int score = 0;
	for (int i = 1; i <= N; i++)
	{
		score =max(score, visited[i]);
	}
	res[score].push_back(cur);
	minscore = min(score, minscore);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	for (int i = 1; i <= N; i++)
	{
		visited.assign(N + 1, -1);
		visited[i] = 0;
		q.push(i);
		bfs();
		calc(i);
	}
	cout << minscore << " " << res[minscore].size() << "\n";
	for (int i = 0; i < res[minscore].size(); i++)
	{
		cout << res[minscore][i] << " ";
	}
	return 0;
}