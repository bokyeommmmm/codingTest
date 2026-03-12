#include <iostream>
using namespace std;

int board[101][101];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int t = 0; t < 4; t++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		for (int i = x1; i < x2; i++) {
			for (int j = y1; j < y2; j++) {
				board[i][j] = 1;
			}
		}
	}

	int area = 0;
	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 100; j++) {
			if (board[i][j] == 1) {
				area++;
			}
		}
	}

	cout << area;
	return 0;
}