#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 부분집합을 만들 원본 배열
    vector<int> arr = {3, 6, 7, 1, 5, 4};

    // 배열의 원소 개수
    int n = arr.size();

    // 1 << n == 2^n
    // 원소가 n개일 때 모든 부분집합의 개수
    for (int i = 0; i < (1 << n); i++) {

        // i 하나가 하나의 부분집합을 의미함
        // i를 이진수로 봤을 때 각 비트가 원소 선택 여부
        cout << "{ ";

        // 각 원소를 부분집합에 포함할지 검사
        for (int j = 0; j < n; j++) {

            // i의 j번째 비트가 1인지 확인
            // 1이면 arr[j]를 선택한 것
            if (i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }

        cout << "}" << '\n';
    }

    return 0;
}
