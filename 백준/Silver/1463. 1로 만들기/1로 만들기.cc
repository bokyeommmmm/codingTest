#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001]; // dp[i] = i를 1로 만드는 최소 연산 횟수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    dp[1] = 0; // 1은 이미 1이므로 연산 0번

    for (int i = 2; i <= N; i++) {
        // 1을 빼는 경우: i -> i-1
        dp[i] = dp[i - 1] + 1;

        // 2로 나누어 떨어지는 경우: i -> i/2
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        // 3으로 나누어 떨어지는 경우: i -> i/3
        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
    }

    cout << dp[N] << '\n';
    return 0;
}
