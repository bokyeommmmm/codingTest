#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

int L, C;
vector<char> list;

void dfs(int idx, string str, int aieou, int bcd, int cnt) // 모음의 수 , 자음의 수
{
    if (cnt == L && aieou >= 1 && bcd >= 2)
    {
        cout << str << "\n";
        return;
    }
    else if (cnt == L || idx == C)
    {
        return;
    }
    if (list[idx] == 'a' || list[idx] == 'i' || list[idx] == 'e' || list[idx] == 'o' || list[idx] == 'u')
        dfs(idx + 1, str + list[idx], aieou + 1, bcd, cnt + 1);
    else
        dfs(idx + 1, str + list[idx], aieou, bcd + 1, cnt + 1);
    dfs(idx + 1, str, aieou, bcd, cnt);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;

    char c;
    for (int i = 0; i < C; i++)
    {
        cin >> c;
        list.push_back(c);
    }
    sort(list.begin(), list.end());
    dfs(0, "", 0, 0, 0);

    return 0;
}