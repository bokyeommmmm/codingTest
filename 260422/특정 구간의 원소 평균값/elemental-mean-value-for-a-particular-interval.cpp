#include <iostream>
#include<vector>
using namespace std;

int N, res;
vector<int>arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}
	res += N;
	for (int i = 2; i <= N; i++) //구간 크기 i
	{
		for (int j = 0; j <= N - i; j++) //시작지점 : j
		{
			int sum = 0;
			bool flag = false;
			for (int k = j; k < j + i; k++)
			{
				sum += arr[k];
			}

			for (int k = j; k < j + i; k++)
			{
				if (arr[k] * i == sum && flag == false)
				{
					flag = true;
					res++;
				}
			}
		}
	}
	cout << res;
	return 0;
}