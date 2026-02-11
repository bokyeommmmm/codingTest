#include <iostream>
#include<vector>
using namespace std;

int N, S;
int res = 0;
vector<int> arr;
void func(int cnt, int sum)
{
	if (cnt ==N && sum == S)
	{
		res++;
	}
	if (cnt == N)
		return;
	func(cnt + 1, sum + arr[N - cnt - 1]);
	func(cnt + 1, sum);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;


	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		arr.push_back(temp);
	}
	func(0, 0);
	if (S == 0)res--;
	cout << res;
}