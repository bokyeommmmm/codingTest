#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M, H;
int dr[6] = { 0, 0, 1, -1, 0, 0 };
int dc[6] = { 1, -1, 0, 0, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };

struct rch {
	int r;
	int c;
	int h;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> M >> N >> H;
	vector<vector<vector<int>>> map(H, vector<vector<int>>(N, vector<int>(M)));

	queue<rch> q;

	for (int h = 0; h < H; h++) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				cin >> map[h][r][c];
				if (map[h][r][c] == 1) {
					q.push({ r, c, h }); 
				}
			}
		}
	}

	while (!q.empty()) {
		int r = q.front().r;
		int c = q.front().c;
		int h = q.front().h;
		q.pop();

		for (int d = 0; d < 6; d++) {
			int nr = r + dr[d];
			int nc = c + dc[d];
			int nh = h + dh[d];

			if (nr < 0 || nc < 0 || nh < 0 || nr >= N || nc >= M || nh >= H)
				continue;
			if (map[nh][nr][nc] != 0) 
				continue;

			map[nh][nr][nc] = map[h][r][c] + 1;
			q.push({ nr, nc, nh });
		}
	}

	int mx = 1;
	for (int h = 0; h < H; h++) {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < M; c++) {
				if (map[h][r][c] == 0) { 
					cout << -1;
					return 0;
				}
				if (map[h][r][c] > mx) mx = map[h][r][c];
			}
		}
	}

	
	cout << mx - 1;
	return 0;
}
