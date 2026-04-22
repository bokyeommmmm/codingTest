#include <iostream>
#include<algorithm>
using namespace std;

int N, K, res;
int arr[10001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int temp;
		char c;
		cin >> temp >> c;
		if (c == 'G')
			arr[temp] = 1;
		else
			arr[temp] = 2;
	}
	for (int i = 1; i <= 10000-K; i++)
	{
		int sum = 0;
		for (int j = 0; j <= K; j++)
		{
			sum += arr[i + j];

		}
		res = max(res, sum);
	}
	cout << res;
	return 0;
}