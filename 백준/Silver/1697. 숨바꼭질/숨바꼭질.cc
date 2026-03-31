#include <iostream>
#include <vector>
#include<queue>
using namespace std;

int N, K;
queue<int>q;
vector<int>visited;
void bfs()
{
	while (!q.empty())
	{

		int cur = q.front();
		q.pop();
		if (cur == K)
		{
			return;
		}

		int next = cur * 2;
		if (next<=100000 && visited[next] == -1 ) //방문한적없으면 
		{
			visited[next] = visited[cur]+1;
			q.push(next);

		}
		next = cur - 1;
		if (next >= 0 && visited[next] == -1 )
		{
			visited[next] = visited[cur] + 1;
			q.push(next);

		}
		next = cur + 1;
		if (next <= 100000 && visited[next] == -1 ) //방문한적없거나 
		{
			visited[next] = visited[cur]+1;

			q.push(next);

		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	visited.assign(100001, -1);
	

	visited[N] = 0;
	q.push(N);
	bfs();


	cout << visited[K];
	return 0;
}