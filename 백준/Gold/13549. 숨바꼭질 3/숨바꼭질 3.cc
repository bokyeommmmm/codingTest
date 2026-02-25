#include <iostream>
#include<vector>
#include<queue>
using namespace std;

int N, K;
vector<int>visited;
queue<int>q;
int MAX = 100001;
void bfs()
{
	while (!q.empty())
	{
		int now = q.front();
		q.pop();

		if (now == K)
		{
			cout << visited[now];
			return;
		}

		if (now * 2 <= MAX && visited[now * 2] == -1)
		{
			visited[now * 2] = visited[now];
			q.push(now * 2);
		}

		if (now - 1 >= 0 && visited[now - 1] == -1)
		{
			visited[now - 1] = visited[now] + 1;
			q.push(now - 1);
		}
		if (now + 1 <= MAX && visited[now + 1] == -1)
		{
			visited[now + 1] = visited[now] + 1;
			q.push(now + 1);
		}

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	visited.assign(MAX + 1, -1);

	visited[N] = 0;
	q.push(N);

	bfs();

	return 0;
}