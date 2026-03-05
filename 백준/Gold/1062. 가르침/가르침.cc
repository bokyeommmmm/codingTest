#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int N, K, res; //단어 수 , 알파벳 수 
vector<int>visited;
vector<string>str;
vector<int>candidate;
void calc()
{
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		bool ok = true;
		for (int j = 4; j < str[i].size() - 4; j++)
		{
			int a = str[i][j] - 'a';
			if (visited[a] == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			cnt++;
		}
	}
	res = max(res, cnt);
}

void dfs(int idx, int cnt)
{
	if (cnt == K)
	{
		calc();
		return;
	}
	if (idx == (int)candidate.size()) 
	{ // 후보 다 봤으면
		calc();
		return;
	}
	visited[candidate[idx]] = 1;
	dfs(idx + 1, cnt + 1);
	visited[candidate[idx]] = 0;
	dfs(idx + 1, cnt);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	visited.assign(26, 0);

	if (K < 5)
	{
		cout << 0;
		return 0;
	}
	if (K == 26)
	{
		cout << N;
		return 0;
	}
	for (int i = 0; i < N; i++)
	{
		string temp;
		cin >> temp;
		str.push_back(temp);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < str[i].size(); j++)
		{
			char temp = str[i][j];
			{
				if (visited[temp - 'a'] == 0 && temp != 'a'&&temp != 'n'&&temp != 't'&&temp != 'i'&&temp != 'c')
				{
					visited[temp - 'a'] = 1;
					candidate.push_back(temp - 'a');
				}
			}
		}
	}


	visited.assign(26, 0);
	visited['a' - 'a'] = 1;
	visited['n' - 'a'] = 1;
	visited['t' - 'a'] = 1;
	visited['i' - 'a'] = 1;
	visited['c' - 'a'] = 1;

	dfs(0, 5);

	cout << res;
	return 0;
}