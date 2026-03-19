#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int T, N, MIN, MAX, cur;
int sign[4]; // + - * /
vector<int>nums;

void dfs(int cnt)
{
	if (cnt == N - 1)
	{
		MAX = max(cur, MAX);
		MIN = min(cur, MIN);
		return;
	}

	int prev = cur;
	if (sign[0] > 0)
	{
		sign[0]--;
		cur = cur + nums[cnt + 1];
		dfs(cnt + 1);
		sign[0]++;
		cur = prev;
	}

	if (sign[1] > 0)
	{
		sign[1]--;
		cur = cur - nums[cnt + 1];
		dfs(cnt + 1);
		sign[1]++;
		cur = prev;
	}

	if (sign[2] > 0)
	{
		sign[2]--;
		cur = cur * nums[cnt + 1];
		dfs(cnt + 1);
		sign[2]++;
		cur = prev;
	}

	if (sign[3] > 0)
	{
		sign[3]--;
		cur = cur / nums[cnt + 1];
		dfs(cnt + 1);
		sign[3]++;
		cur = prev;
	}
}

void init() {
	nums.clear();
	MIN = 1000000000;
	MAX = -1000000000;
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		cin >> sign[i];
	}
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	cur = nums[0];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();

		dfs(0);

		cout << "#" << tc << " " << MAX - MIN << "\n";
	}
	return 0;
}