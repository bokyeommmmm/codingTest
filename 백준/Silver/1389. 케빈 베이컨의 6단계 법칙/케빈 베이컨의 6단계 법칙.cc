#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, M;
vector<vector<int>>graph;
vector<int>visited;
queue<int>q;
int res = 1;
int score = 10000;
int calc()
{
	int sum = 0;
	for (int i = 0; i < visited.size(); i++)
	{
		sum += visited[i];
	}
	return sum;
}
void bfs()
{
	while (!q.empty())
	{
		int user = q.front();
		q.pop();
		for (int i = 0; i < graph[user].size(); i++)
		{
			int next = graph[user][i];
			if (visited[next] != -1)
				continue;
			visited[next] = visited[user] + 1;
			q.push(next);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	graph.assign(N+1, vector<int>());

	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= N; i++)
	{
		visited.assign(N + 1, -1);
		while (!q.empty())
		{
			q.pop();
		}
		q.push(i);
		visited[i] = 0;
		bfs();
		visited[0] = 0;
		if (calc() < score)
		{
			score = calc();
			res = i;
		};
	}
	cout << res;
	return 0;
}