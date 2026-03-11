#include <iostream>
#include <vector>
#include<queue>
#include<algorithm>
using namespace std;

int N, res;
vector<vector<int>> info;
vector<int>visited;
vector<int>arr;

void simul()
{
	int score = 0;
	int idx = 0;
	int out;
	int base[3] = {};
	for (int inning = 0; inning < N; inning++)
	{
		out = 0;
		base[0] = 0;
		base[1] = 0;
		base[2] = 0;

		while (out < 3)
		{
			int num = arr[idx]; //순열로 나온 사람의 인덱스. 
			int temp = info[inning][num]; //이번 사람의 이번 이닝 결과 
			if (temp == 0)
				out++;
			else if (temp == 1)
			{
				score += base[2];
				base[2] = base[1];
				base[1] = base[0];
				base[0] = 1;
			}
			else if (temp == 2)
			{
				int sum = 0;
				for (int i = 1; i < 3; i++)
				{
					sum += base[i];
				}
				score += sum;
				base[2] = base[0];
				base[1] = 1;
				base[0] = 0;
			}
			else if (temp == 3)
			{
				int sum = 0;
				for (int i = 0; i < 3; i++)
				{
					sum += base[i];
				}
				score += sum;
				base[0] = 0;
				base[1] = 0;
				base[2] = 1;
			}
			else if (temp == 4)
			{
				int sum = 0;
				for (int i = 0; i < 3; i++)
				{
					sum += base[i];
				}
				score++;
				score += sum;
				base[0] = 0;
				base[1] = 0;
				base[2] = 0;
			}
			idx = (idx + 1) % 9;
		}

	}
	res = max(score, res);

}
void dfs(int cnt)
{
	if (cnt == 9)
	{
		simul();
		return;
	}
	if (cnt == 3)
	{
		arr.push_back(0);
		dfs(cnt + 1);
		arr.pop_back();
	}
	else
	{
		for (int i = 1; i < 9; i++)
		{
			if (visited[i] == 0)
			{
				visited[i] = 1;
				arr.push_back(i);
				dfs(cnt + 1);
				visited[i] = 0;
				arr.pop_back();
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	info.assign(N, vector<int>(9));
	visited.assign(9, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> info[i][j];
		}
	}

	dfs(0); //0번선수 -> 4번타자. 
	cout << res;
	return 0;
}