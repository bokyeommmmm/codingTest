#include <iostream>
#include <algorithm>
using namespace std;

int n, res;
int A[100];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
    res = 1000000000;
	for (int i = 0; i < n; i++) {

		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			int dist = abs(i - j); //j번째 집이 i모일 집과의 거리
			sum = sum + (dist * A[j]);
		}
		res = min(res, sum);
	}
	cout << res;
	return 0;
}