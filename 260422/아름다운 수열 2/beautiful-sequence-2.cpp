#include <iostream>
#include <vector>
using namespace std;
int num[101];
int res;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<int>arr;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}
	for (int i = 0; i < M; i++)
	{
		int t;
		cin >> t;
		num[t]++;
	}
	for (int i = 0; i <= N-M; i++)
	{
		int temp[101];
		for (int j = 0; j < 101; j++)
		{
			temp[j] = num[j];
		}
		bool flag = true;
		for (int j = i; j < i+M; j++)
		{
			temp[arr[j]]--;
			if (temp[arr[j]] < 0)
				flag = false;
		}
		if (flag)
			res++;
	}
	cout << res;
	return 0;
}