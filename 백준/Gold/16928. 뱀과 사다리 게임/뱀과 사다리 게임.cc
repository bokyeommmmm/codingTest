#include <iostream>
#include<map>
#include<queue>
#include <vector>
using namespace std;
int N, M;
int dice[6] = { 6,5,4,3,2,1 };
map<int, int>m;
queue<int>q;
vector<int>cost;

void bfs()
{
	while (!q.empty())
	{
		int now = q.front();
		q.pop();
		if (now >= 100)
		{
			return;
		}
		for (int i = 0; i < 6; i++)
		{
			int next = now + dice[i];
			if (next > 100)
				continue;
			if (m.count(next) == 1)
			{
				next = m[next];
			}
			if (cost[next] < cost[now] + 1)
				continue;
			

			cost[next] = cost[now] + 1;
			q.push(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	cost.assign(101, 100);
	for (int i = 0; i < N+M; i++)
	{
		int from, to;
		cin >> from >> to;
		m.insert({ from,to });
	}
	q.push(1);
	cost[1] = 0;
	bfs();
	cout << cost[100];
	return 0;
}