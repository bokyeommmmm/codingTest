#include <iostream>
#include<algorithm>
using namespace std;

int N, totalLength, maxSkip;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	int x_2, y_2, x_1, y_1;
	cin >> x_2 >> y_2;
	cin >> x_1 >> y_1;
	totalLength = totalLength + abs(x_2 - x_1) + abs(y_2 - y_1);

	for (int i = 2; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		int dist = abs(x_1 - x) + abs(y_1 - y);
		totalLength += dist;
		maxSkip = max(maxSkip, abs(x_2 - x_1) + abs(y_2 - y_1) + abs(x_1 - x) + abs(y_1 - y) - (abs(x_2 - x) + abs(y_2 - y)));
		x_2 = x_1;
		x_1 = x;
		y_2 = y_1;
		y_1 = y;
	}

	cout << totalLength - maxSkip;

	return 0;
}