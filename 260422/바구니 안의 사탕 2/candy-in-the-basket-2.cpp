#include <iostream>
#include<vector>
using namespace std;

int N, K, res, maxAmt;
vector<int>arr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	arr.assign(101, 0);
	for (int i = 0; i < N; i++)
	{
		int pos, amt;
		cin >> amt >> pos;
		arr[pos] += amt;
	}

	for (int i = 1+K; i < 100-K; i++) //i : 증심 위치. 
	{
		int sum = 0;
		for (int j = i-K; j <= i+K; j++)
		{
			sum += arr[j];
		}
		if (maxAmt < sum)
		{
			res = i;
			maxAmt = sum;
		}
	}

	cout << maxAmt;
	return 0;
}