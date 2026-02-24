#include <iostream>
#include<vector>

using namespace std;

int N, M;
vector<int>arr;
vector<int>visited;
vector<int>res;
void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << res[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 1)
			continue;
		visited[i] = 1;
		res.push_back(i);
		dfs(cnt + 1);
		visited[i] = 0;
		res.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	arr.assign(N + 1, 0);
	visited.assign(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		arr[i] = i;
	}
	dfs(0);
	return 0;
}