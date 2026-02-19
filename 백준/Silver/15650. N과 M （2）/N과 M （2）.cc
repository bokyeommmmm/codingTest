#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> arr;

void dfs(int idx, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i <= N; i++)
	{
		arr[cnt] = i;
		dfs(i + 1, cnt + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	arr.assign(M, 0);
	dfs(1, 0);
	return 0;
}
