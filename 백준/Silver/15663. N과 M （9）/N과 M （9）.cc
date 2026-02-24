#include <iostream>
#include<set>
#include <vector>
#include<algorithm>
using namespace std;
int N, M;
vector<int>s;
set<vector<int>> res;
vector<int>arr;
vector<int>visited;
void dfs(int idx , int cnt)
{
	if (cnt == M)
	{
		res.insert(arr);
		return;
	}
	for (int i = 0; i < s.size(); i++)
	{
		if (visited[i] == 1)
			continue;
		visited[i] = 1;	
		arr.push_back(s[i]);
		dfs(idx+1, cnt + 1);
		arr.pop_back();
		visited[i] = 0;

	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		s.push_back(temp);
	}
	sort(s.begin(), s.end());
	visited.assign(N, 0);
	dfs(0,0);

	for (auto a : res)
	{
		for (int i = 0; i < a.size(); i++)
		{
			cout << a[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}