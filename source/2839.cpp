#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int res = 0;

    if (N % 5 == 0) {
        res = N / 5;
        cout << res;
        return 0;
    }

    bool ok = false; // 해답 찾았는지 여부

    for (;;) {
        res++;  // 3kg 봉지 하나 더 써본다
        int remain = N - 3 * res;  // 남은 설탕 양

        if (remain < 0) {
            // 더 이상 3kg을 빼면 설탕이 음수가 되므로 불가능
            break;
        }

        if (remain % 5 == 0) {
            // 남은 양이 5로 딱 나누어 떨어지면 성공
            res += remain / 5; // 5kg 봉지 개수 추가
            ok = true;
            break;
        }
    }

    if (!ok) {
        cout << -1;
    } else {
        cout << res;
    }

    return 0;
}
