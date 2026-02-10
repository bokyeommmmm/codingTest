#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int S[20][20];
int answer = 2100000000;

vector<int> teamA;

void dfs(int idx) {
	if (teamA.size() == N / 2) {   //팀다짜면
		bool inA[20] = { false };

		for (int i = 0; i < teamA.size(); i++) {
			int x = teamA[i];
			inA[x] = true; //A팀 놈들체크하고 
		}
		int scoreA = 0, scoreB = 0;

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (inA[i] && inA[j])              //같은팀놈들 계산
					scoreA += S[i][j] + S[j][i];
				else if (!inA[i] && !inA[j])
					scoreB += S[i][j] + S[j][i];
			}
		}

		answer = min(answer, abs(scoreA - scoreB));
		return;
	}
	if (idx == N) return;

	// 이번 녀석 a에 넣고 ㄱㄱ
	teamA.push_back(idx);
	dfs(idx + 1);


	//안넣고
	teamA.pop_back();
	dfs(idx + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> S[i][j];
		}
	}
	teamA.push_back(0);
	dfs(1);

	cout << answer << "\n";
	return 0;
}
