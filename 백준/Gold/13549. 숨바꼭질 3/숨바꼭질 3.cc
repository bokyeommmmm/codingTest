#include <iostream>
#include <vector>
#include<queue>
#include<deque>
using namespace std;

int N, K;
deque<int>q;
vector<int>visited;
vector<int>res;
void bfs()
{
	while (!q.empty())
	{

		int cur = q.front();
		q.pop_front();

		if (visited[K] != -1 && visited[cur] > visited[K])
			break;
		if (cur == K)
		{
			res[visited[K]]++;
			return;
		}

		int next = cur * 2;
		if (next<=100000 && (visited[next] == -1 || visited[next] >= visited[cur] + 1)) //방문한적없으면 
		{
			visited[next] = visited[cur];
			q.push_front(next);

		}
		next = cur - 1;
		if (next >= 0 && (visited[next] == -1 || visited[next] >= visited[cur] + 1))
		{
			visited[next] = visited[cur] + 1;
			q.push_back(next);

		}
		next = cur + 1;
		if (next <= 100000 && (visited[next] == -1||visited[next]>=visited[cur]+1) ) //방문한적없거나 
		{
			visited[next] = visited[cur]+1;

			q.push_back(next);

		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	visited.assign(100001, -1);
	res.assign(100001,0);

	visited[N] = 0;
	q.push_back(N);
	bfs();


	cout << visited[K];
	return 0;
}