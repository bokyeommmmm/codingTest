#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int H, W, res;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M, K;
	int X, Y;
	int answer = 0;

	cin >> N >> M;
	vector<int> v(M);

	for (int i = 0; i < M; i++)
		cin >> v[i];

	for (int i = 1; i < M - 1; i++) {
		int left = 0; int right = 0;

		for (int j = 0; j < i; j++)
			left = max(left, v[j]);
		for (int j = M - 1; j > i; j--) 
			right = max(right, v[j]);
		answer += max(0, min(left, right) - v[i]);
	}

	cout << answer << endl;
	return 0;
}