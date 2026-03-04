#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

int N;

vector<pair<int, int>> map;
vector<int>visited;
queue<int> q;

void bfs()
{
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now == N + 1)
			return;
		for (int i = 0; i < N+2; i++)
		{
			if (visited[i] == 1)
				continue;
			int dist = abs(map[now].first - map[i].first) + abs(map[now].second - map[i].second);
			if (dist <= 1000)
			{
				visited[i] = 1;
				q.push(i);
			}
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;         //init 
		map.clear();
		visited.assign(N + 2,0);
		while (!q.empty())
		{
			q.pop();
		}
		 //-------
		for (int i = 0; i < N+2; i++)
		{
			int x, y;
			cin >> x >> y;
			map.push_back({ x,y });
		}
		visited[0] = 1;
		q.push(0);
		bfs();

		if (visited[N + 1] == 1)
			cout << "happy\n";
		else
			cout << "sad\n";
	}

	return 0;
}