#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Meeting {
	int start, end;
};

bool cmp(const Meeting &a, const Meeting &b) {
	if (a.end != b.end) return a.end < b.end;
	return a.start< b.start;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<Meeting> v;

	for (int i = 0; i < N; i++) {
		Meeting m;
		cin >> m.start >> m.end;
		v.push_back(m);
	}

	sort(v.begin(), v.end(), cmp);

	int cnt = 0;
	int lastEnd = 0;

	for (int i = 0; i < N; i++) {
		if (v[i].start >= lastEnd) {
			cnt++;
			lastEnd = v[i].end;
		}
	}

	cout << cnt;
	return 0;
}