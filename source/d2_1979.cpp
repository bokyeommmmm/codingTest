#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<vector<int> >& a, int N, int K) {
    int ans = 0;

    // 가로
    for (int i = 0; i < N; i++) {
        int cnt = 0;
        for (int j = 0; j < N; j++) {
            if (a[i][j] == 1) cnt++;
            else {
                if (cnt == K) ans++;
                cnt = 0;
            }
        }
        //경계 처리
        if (cnt == K) ans++;
    }

    // 세로 
    for (int j = 0; j < N; j++) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (a[i][j] == 1) cnt++;
            else {
                if (cnt == K) ans++;
                cnt = 0;
            }
        }
        if (cnt == K) ans++;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N, K;
        cin >> N >> K;

        vector<vector<int> > a(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> a[i][j];
            }
        }

        cout << "#" << tc << " " << solve(a, N, K) << "\n";
    }
    return 0;
}
