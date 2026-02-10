#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    map<int, int> m;

    int N, M;
    int res = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        res = max(res, temp);
        if (m.find(temp) == m.end()) // 없으면
        {
            m.insert({temp, 1});
        }
        else if (m.find(temp) != m.end())
        {
            m[temp]++;
        }
    }
    int woods = 0; // 사정권 나무
    int sum = 0;   // 자른 나무.
    int H;
    for (H = res; H >= 0; H--)
    {
        // cout << sum;
        sum += woods;
        if (sum >= M)
           break;
        if (m.count(H))
        {
            woods += m[H];
        }
    }
    cout << H;
    return 0;
}