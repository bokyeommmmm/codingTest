#include <iostream>
#include <algorithm>
using namespace std;

int dp[301];
int stepArr[301]; // 가변 배열 말고 그냥 301로 잡자 (N ≤ 300 이라 충분)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> stepArr[i];
    }

    if (N == 1) {
        cout << stepArr[1];
        return 0;
    }

    dp[1] = stepArr[1];
    dp[2] = stepArr[1] + stepArr[2];

    if (N == 2) {
        cout << dp[2];
        return 0;
    }

    for (int i = 3; i <= N; i++) {
        dp[i] = max(
            dp[i-2] + stepArr[i],                // (i-2) → i
            dp[i-3] + stepArr[i-1] + stepArr[i]  // (i-3) → (i-1) → i
        );
    }

    cout << dp[N] << '\n';
    return 0;
}
