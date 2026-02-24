#include <iostream>
#include<set>
#include <vector>
using namespace std;
int N, M;
set<int>s;
set<vector<int>> res;
vector<int>arr;
bool isup(vector<int> &arr)
{
	for (int i = 0; i < arr.size()-1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}
void dfs(int cnt)
{
	if (cnt == M)
	{
		if (isup(arr)) 
		{
			res.insert(arr);
		}
		return;
	}
	for (const auto & k :s)
	{
		arr.push_back(k);
		dfs(cnt + 1);
		arr.pop_back();
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
		s.insert(temp);
	}
	dfs(0);
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