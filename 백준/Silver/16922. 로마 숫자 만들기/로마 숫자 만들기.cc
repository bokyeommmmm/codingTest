#include <iostream>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	set<int> s;

	for (int a = 0; a <= N; a++) {
		for (int b = 0; b <= N - a; b++) {
			for (int c = 0; c <= N - a - b; c++) {
				int d = N - a - b - c;
				int sum = a * 1 + b * 5 + c * 10 + d * 50;
				s.insert(sum);
			}
		}
	}

	cout << s.size();
}
