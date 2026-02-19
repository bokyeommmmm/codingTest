#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;

	cin >> N >> K;
	vector<int> res;
	vector<int> arr;
	for (int i = 1; i <= N; i++)
	{
		arr.push_back(i);
	}
	int cnt = 0;
	int idx = -1;
	while (cnt < N)
	{
		int pass = 0;
		while (pass<K)
		{
			idx++;
			idx %= N;
			while (arr[idx]==0)
			{
				idx++;
				idx %= N;
			}
			pass++;
		}
		res.push_back(arr[idx]);
		cnt++;
		arr[idx] = 0;
	}
	cout << "<";
	for (int i = 0; i < res.size() - 1; i++)
	{
		cout << res[i] << ", ";
	}
	cout << res[res.size() - 1] << ">";

	return 0;
}