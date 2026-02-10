#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    map<string, int> mp;

    for (int i = 0; i < N; i++)
    {
        string x;
        cin >> x;
        mp[x] = 1;   // 듣도 못한 사람 표시
    }

    map<string, int> result;

    for (int i = 0; i < M; i++)
    {
        string x;
        cin >> x;
        if (mp.count(x))
            result[x] = 1;   // 듣보잡
    }

    cout << result.size() << "\n";

    map<string, int>::iterator it;
    for (it = result.begin(); it != result.end(); ++it)
    {
        cout << it->first << "\n";
    }

    return 0;
}
