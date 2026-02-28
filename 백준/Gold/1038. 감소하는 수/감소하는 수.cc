#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

void dfs(long long num, int last)
{
    v.push_back(num);

    for (int i = 0; i < last; i++)
    {
        dfs(num * 10 + i, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < 10; i++)
    {
        dfs(i, i);
    }

    sort(v.begin(), v.end());

    if (N >= v.size())
        cout << -1;
    else
        cout << v[N];

    return 0;
}