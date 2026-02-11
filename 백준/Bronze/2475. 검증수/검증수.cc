#include <iostream>
using namespace std;

int main() {

    int x, sum = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> x;
        sum = (sum + x * x) % 10;
    }
    cout << sum;
    return 0;
}
