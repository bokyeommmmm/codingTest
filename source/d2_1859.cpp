#include <queue>
#include <vector>
#include<iostream>
using namespace std;

long long maxProfit(queue<int> prices) {
    long long sum = 0;

    while (!prices.empty()) {
        vector<int> v;
        queue<int> tmp = prices;
        while (!tmp.empty()) {
            v.push_back(tmp.front());
            tmp.pop();
        }

        int max_ = v[0];
        int maxIdx = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            if (v[i] >= max_) {
                max_ = v[i];
                maxIdx = i;
            }
        }

        for (int j = 0; j < maxIdx; j++) {
            sum += (max_ - prices.front());
            prices.pop();
        }

        prices.pop();
    }

    return sum;
}

int main() {
    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        queue<int> prices;
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            prices.push(temp);
        }

        cout << "#" << tc << " " << maxProfit(prices) << "\n";
    }
    return 0;
}