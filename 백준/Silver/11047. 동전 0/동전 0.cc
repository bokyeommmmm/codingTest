#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;

vector<int>coin;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	int res = 0;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		coin.push_back(temp);
	}

	for (int i = N-1; i >=0; i--)
	{
		if (coin[i] <=K)
		{
			res =res +  (K / coin[i]);
			K = K % coin[i];
		}
	}

	cout << res;
	return 0;
}