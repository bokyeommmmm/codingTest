#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, minSum;;
vector<vector<int>>graph;
vector<int>visited;

queue<int>q;

void bfs(int idx)
{
	int sum = 0;

	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < N; i++)
		{
			if (graph[cur][i] == 1)
			{
				int next = i;
				if (visited[next] == -1)
				{
					visited[next] = visited[cur] + 1;
					sum += visited[i];
					if (sum >= minSum)
					{
						while (!q.empty())
						{
							q.pop();
						}
						return;
					}
					q.push(next);
				}
			}
		}
	}
	if (minSum > sum)
	{
		minSum = sum;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		graph.assign(N, vector<int>(N));
		minSum = 1000000000;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> graph[i][j];
			}
		}
		for (int i = 0; i < N; i++)
		{
			visited.assign(N, -1);
			visited[i] = 0;
			q.push(i);
			bfs(i);
		}
		cout << "#" << tc << " " << minSum << "\n";
	}
	return 0;
}