#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 정렬 기준을 정의하는 compare 함수
bool compare(const pair<int,int>& a, const pair<int,int>& b) {
    if (a.second == b.second) {
        // y좌표가 같으면 x좌표 오름차순
        return a.first < b.first;
    }
    // 기본은 y좌표 오름차순
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<pair<int,int>> points(N);

    // 입력 받기
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;  // (x, y)
    }

    // compare 함수를 이용해 정렬
    sort(points.begin(), points.end(), compare);

    // 출력
    for (int i = 0; i < N; i++) {
        cout << points[i].first << " " << points[i].second << "\n";
    }

    return 0;
}
