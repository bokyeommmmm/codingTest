#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, K, res;
vector<int>arr;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < N-K+1; i++)
	{
		int sum = 0;
		for (int j = 0; j < K; j++)
		{
			sum += arr[i + j];
		}
		res = max(res, sum);
	}
	cout << res;
	return 0;
}