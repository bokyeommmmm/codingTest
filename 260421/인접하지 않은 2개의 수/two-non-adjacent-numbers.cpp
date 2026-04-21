#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, res;
vector<int>arr;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}

	for (int i = 0; i < N-2; i++)
	{
		for (int j = i+2; j < N; j++)
		{
			res = max(res, arr[i] + arr[j]);
		}
	}
	cout << res;

	return 0;
}