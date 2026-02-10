#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    int mask = 0;
    for (int i = 0; i < N; i++)
    {
        string s;
        int num;
        cin >> s >> num;
        
        if (s == "add")
        {
            mask = mask | (1 << (num - 1));  // num-1로 비트마스크 처리
        }
        else if (s == "remove")
        {
            mask = mask & ~(1 << (num - 1)); // num-1로 비트마스크 처리
        }
        else if (s == "check")
        {
            if (mask & (1 << (num - 1))) // num-1로 비트마스크 처리
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        }
        else if (s == "toggle")
        {
            mask = mask ^ (1 << (num - 1));  // num-1로 비트마스크 처리
        }
        else if (s == "all")
        {
            mask = (1 << 20) - 1;  // 1부터 20까지 모든 비트를 1로 설정
        }
        else if (s == "empty")
        {
            mask = 0;  // 모든 비트를 0으로 설정
        }
    }

    return 0;
}
