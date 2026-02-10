#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 1; tc <= 10; tc++) {
        int N;
        cin >> N;
        vector<int> h(N);
        for (int i = 0; i < N; i++) 
            cin >> h[i];

        int ans = 0;
        for (int i = 2; i < N - 2; i++) {
            int near_max = max(
                max(h[i-2], h[i-1]),
                max(h[i+1], h[i+2])
            );
            if (h[i] > near_max) ans += h[i] - near_max;
        }

        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}
