#include <iostream>
#include <vector>
#include <algorithm> // max, min 함수를 위해 추가

using namespace std;

int N, K, maxAmt;
vector<int> arr;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;

	arr.assign(101, 0);

	for (int i = 0; i < N; i++) {
		int amt, pos;
		cin >> amt >> pos;
		if (pos <= 100) {
			arr[pos] += amt;
		}
	}

	for (int i = 0; i <= 100; i++) {
		int sum = 0;

		int start = max(0, i - K);
		int end = min(100, i + K);

		for (int j = start; j <= end; j++) {
			sum += arr[j];
		}

		if (maxAmt < sum) {
			maxAmt = sum;
		}
	}

	cout << maxAmt;

	return 0;
}