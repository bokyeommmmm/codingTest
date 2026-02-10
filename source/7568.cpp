#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int weight[50];
    int height[50];

    for (int i = 0; i < N; i++) {
        cin >> weight[i] >> height[i];
    }

    for (int i = 0; i < N; i++) {
        int rank = 1;

        for (int j = 0; j < N; j++) {
            if (weight[j] > weight[i] && height[j] > height[i]) {
                rank++;
            }
        }

        cout << rank << " ";
    }

    return 0;
}
