#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> arr;
vector<int>res;
vector<int>visited;
void dfs(int idx, int cnt)
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

	for (int i = 0; i < N; i++)
	{
		if (visited[i] == 0)
		{
		visited[i] = 1;
		res[cnt] = arr[i];
		dfs(i + 1, cnt + 1);
		visited[i] =0;
		}

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	res.assign(M, 0);
	visited.assign(N, 0);
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	sort(arr.begin(), arr.end());
	dfs(0, 0);
	return 0;
}
