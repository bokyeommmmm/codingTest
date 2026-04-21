#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, res;
vector<int>arr;

void test(int a, int b, int c)
{
	if (a / 10000 + b / 10000 + c / 10000 > 9)
		return;
	if (((a % 10000) / 1000) + ((b % 10000) / 1000) + ((c % 10000) / 1000) > 9)
		return;
	if (((a % 1000) / 100) + ((b % 1000) / 100) + ((c % 1000) / 100) > 9)
		return;
	if (((a % 100) / 10) + ((b % 100) / 10) + ((c % 100) / 10) > 9)
		return;
	if ((a % 10) + (b % 10) + (c % 10) > 9)
		return;
	res = max(a + b + c, res);
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	res = -1;

	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	for (int i = 0; i < N - 2; i++)
		for (int j = i + 1; j < N - 1; j++)
			for (int k = j + 1; k < N; k++)
				test(arr[i], arr[j], arr[k]);
	cout << res;
	return 0;
}