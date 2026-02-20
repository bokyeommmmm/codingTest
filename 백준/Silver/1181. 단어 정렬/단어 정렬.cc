#include<iostream>
#include<string>
#include<vector>
#include<set>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<set<string>>arr(51);
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		arr[str.size()].insert(str);
	}
	for (int i = 1; i <= 50; i++)
	{
		for (auto it = arr[i].begin(); it != arr[i].end(); ++it)
		{
			cout << *it << "\n";
		}

	}


	return 0;
}