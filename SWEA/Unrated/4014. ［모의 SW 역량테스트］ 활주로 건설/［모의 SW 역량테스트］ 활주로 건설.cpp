#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, X, res;
vector<vector<int>> board;

//전부 높이 *2 -> 경사로 설치를 해당 X만ㄴ큼 +1 --> 검사할때 높이차 1 이하면 이륙허가.
bool dfsLine(const vector<int>& line,
	vector<int>& surf,
	vector<int>& used,
	int idx)
{
	if (idx >= N - 1) return true;

	int cur = line[idx];
	int nxt = line[idx + 1];

	if (cur == nxt)
		return dfsLine(line, surf, used, idx + 1);

	if (abs(cur - nxt) >= 2)
		return false;

	if (cur == nxt + 1) {
		if (idx + X >= N) return false;

		for (int k = 1; k <= X; k++) {
			int p = idx + k;
			if (line[p] != nxt) return false;
			if (used[p]) return false;
		}

		for (int k = 1; k <= X; k++) {
			int p = idx + k;
			used[p] = 1;
			surf[p] += 1; 
		}

		return dfsLine(line, surf, used, idx + X);
	}

	if (nxt == cur + 1) {
		if (idx - (X - 1) < 0) return false;

		for (int k = 0; k < X; k++) {
			int p = idx - k;
			if (line[p] != cur) return false;
			if (used[p]) return false;
		}

		for (int k = 0; k < X; k++) {
			int p = idx - k;
			used[p] = 1;
			surf[p] += 1; 
		}

		return dfsLine(line, surf, used, idx + 1);
	}

	return false;
}

bool checkLine(const vector<int>& line)
{
	vector<int> surf(N);
	vector<int> used(N, 0);

	for (int i = 0; i < N; i++)
		surf[i] = line[i] * 2; // 반계단용 스케일(표시만)

	return dfsLine(line, surf, used, 0);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> X;
		board.assign(N, vector<int>(N));
		res = 0;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> board[i][j];

		// 행 검사
		for (int i = 0; i < N; i++)
			if (checkLine(board[i])) res++;

		// 열 검사
		for (int j = 0; j < N; j++) {
			vector<int> col(N);
			for (int i = 0; i < N; i++)
				col[i] = board[i][j];

			if (checkLine(col)) res++;
		}

		cout << "#" << tc << " " << res << "\n";
	}

	return 0;
}
