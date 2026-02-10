#include <queue>
#include<iostream>
using namespace std;

int func(queue<int> &score) {
    int idx = 0;
    int max_cnt=0;
    int cnt[101] = {0};
    while (!score.empty()) {
            cnt[score.front()]++;
            score.pop();
    }
    for (int i = 0; i < 101; i++)
    {
        if(max_cnt<=cnt[i])
        {
            max_cnt=cnt[i];
            idx = i;
        }
    }
    
    return idx;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin >> T;
    

    for (int tc = 1; tc <= T; tc++) {

int N;
    cin >> N;
        queue<int> score;
        for (int j = 0; j < 1000; j++) {
            int temp;
            cin >> temp;
            score.push(temp);
        }

        cout << "#" << tc << " " << func(score) << "\n";
    }
    return 0;
}