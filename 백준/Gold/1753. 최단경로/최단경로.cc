#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int V, E, K;
int INF = 1000000000;

vector<vector<pair<int, int>>> graph;
vector<int> distArr;

void dijkstra(int start)
{
	// {현재까지의 최단거리, 정점번호} 최소힙
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	distArr[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty())
	{
		int dist = pq.top().first;   //정점까지의 거리
		int now = pq.top().second;   //정점 번호
		pq.pop();

		
		if (dist > distArr[now]) // 이미 더 짧은 거리로 처리된 적 있으면 스킵
			continue;

		for (int i = 0; i < graph[now].size(); i++) 
		{
			int next = graph[now][i].first;   // 다음 정점
			int cost = graph[now][i].second;  // 가는 비용

			if (distArr[next] > distArr[now] + cost)
			{
				distArr[next] = distArr[now] + cost;
				pq.push({ distArr[next], next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> V >> E;
	cin >> K;

	graph.assign(V + 1, vector<pair<int, int>>());
	distArr.assign(V + 1, INF);

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;


		graph[u].push_back({ v, w });
	}


	dijkstra(K); //시작 정점부터 ㄱ

	for (int i = 1; i <= V; i++)
	{
		if (distArr[i] == INF)
			cout << "INF\n";   
		else
			cout << distArr[i] << "\n";
	}

	return 0;
}