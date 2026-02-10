#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> path;

void dfs(int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= N; i++)
	{
		if (!path.empty()&&path.back()>i)
		{
			continue;
		}
		path.push_back(i);   
		dfs(cnt + 1);        
		path.pop_back();     
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	dfs(0);
	return 0;
}
