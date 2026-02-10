#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N, M, K;
vector<vector<int>> arr;
vector<pair<int, int>> rc;
vector<int> qs;
stack<int> idx;
vector<int> visited;
int res = 1000000000;
void rotate(vector<vector<int>> &arr1);

void dfs(int cnt)
{
	if (cnt == K) {
		vector<vector<int>>arr1 = arr;
		rotate(arr1);
		return;
	}

	for (int i = 0; i < K; i++)
	{
		if (visited[i] == 0) {
			idx.push(i);
			visited[i] = 1;
			dfs(cnt+1);
			idx.pop();
			visited[i] = 0;
		}
	}
}
void calc(vector<vector<int>>&arr1)
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			sum += arr1[i][j];
		}
		res = min(sum, res);
		sum = 0;
	}
}
void rotate(vector<vector<int>> &arr1)
{

	stack<int> index = idx;
	while (!index.empty())
	{
		int temp = index.top();

		int r = rc[temp].first;
		int c = rc[temp].second;
		int s = qs[temp];

		index.pop();
		for (int i = 1; i <= s; i++)
		{
			int temp = arr1[r - i][c + i];

			for (int j = -i; j < i; j++)
			{
				arr1[r - i][c - j] = arr1[r - i][c - j - 1];
			}

			for (int j = -i; j < i; j++)
			{
				arr1[r + j][c - i] = arr1[r + j + 1][c - i];
			}

			for (int j = -i; j < i; j++)
			{
				arr1[r + i][c + j] = arr1[r + i][c + j + 1];
			}

			for (int j = -i; j < i; j++)
			{
				arr1[r - j][c + i] = arr1[r - j - 1][c + i];
			}

			arr1[r - i + 1][c + i] = temp;
		}
	}
	calc(arr1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> K;
	arr.assign(N + 1, vector<int>(M + 1, 0));
	visited.assign(K, 0);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < K; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		rc.push_back({ a, b });
		qs.push_back(c);
	}
	dfs(0);
	cout << res;
	return 0;
}