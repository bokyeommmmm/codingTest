#include <iostream>
#include <string>
using namespace std;

bool isGroupWord(const string& s) {
    bool seen[26] = { false };

    char prev = 0; // 초기화 필수
    for (int i = 0; i < (int)s.size(); i++) {
        char c = s[i];
        if (c != prev) {
            if (seen[c - 'a']) return false;
            seen[c - 'a'] = true;
            prev = c;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        if (isGroupWord(s)) cnt++;
    }

    cout << cnt;
    return 0;
}
