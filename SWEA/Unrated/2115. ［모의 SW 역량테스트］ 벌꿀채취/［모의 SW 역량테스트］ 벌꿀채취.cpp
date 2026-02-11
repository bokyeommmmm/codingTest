#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int N, M, C;
int res;
vector<vector<int>> map;
vector<vector<int>>visited;
stack<pair<int, int>> A;
stack <pair<int, int>>B;
vector<int>a;
vector<int>b;
vector<int>selected1;
vector<int>selected2;
int a_max = 0;
int b_max = 0;

void honey1(int amt, int sum) {
	a_max = max(a_max, sum);

	for (int i = 0; i < a.size(); i++)
	{
		if (selected1[i] != 0)
		{
			continue;
		}
		if (amt + a[i] > C)
		{
			continue;
		}
		selected1[i] = 1;
		honey1(amt + a[i],sum+ a[i] * a[i]);
		selected1[i] = 0;
	}

}
void honey2(int amt, int sum1) {

	b_max = max(b_max, sum1);
	for (int i = 0; i < a.size(); i++)
	{
		if (selected2[i] != 0)
		{
			continue;
		}
		if (amt + b[i] > C)
		{
			continue;
		}
		selected2[i] = 1;
		honey2(amt + b[i], sum1+b[i] * b[i]);
		selected2[i] = 0;
	}
}
void calc()
{
	a_max = 0;
	b_max = 0;
	stack<pair<int, int>>AA = A;
	stack<pair<int, int>>BB = B;
	while (!a.empty())
	{
		a.pop_back();
		b.pop_back();
	}
	while (!AA.empty() && !BB.empty())
	{
		a.push_back(map[AA.top().first][AA.top().second]);
		b.push_back(map[BB.top().first][BB.top().second]);
		AA.pop();
		BB.pop();
	}
	honey1(0, 0);
	honey2(0, 0);
	res = max(res, a_max + b_max);
}

void dfs(int cnt) {
	if (cnt == 2)
	{
		calc();
		return;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - M + 1; j++)
		{
			bool can_go = true;
			for (int x = 0; x < M; x++)
			{
				if (visited[i][j + x] != 0)
				{
					can_go = false;
				}
			}
			if (can_go)
			{
				for (int x = 0; x < M; x++)
				{
					visited[i][j + x] = cnt + 1;
					if (cnt == 0)
						A.push({ i,j + x });
					else if (cnt == 1)
						B.push({ i,j + x });
				}
				dfs(cnt + 1);
				for (int x = 0; x < M; x++)
				{
					visited[i][j + x] = 0;
					if (cnt == 0)
						A.pop();
					else if (cnt == 1)
						B.pop();
				}
			}
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M >> C;

		map.assign(N, vector<int>(N, 0));
		visited.assign(N, vector<int>(N, 0));
		selected1.assign(M, 0);
		selected2.assign(M, 0);
		res = 0;
		a_max = 0;
		b_max = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
			}
		}
		dfs(0);
		cout << "#" << tc << " " << res << "\n";
	}

	return 0;

}