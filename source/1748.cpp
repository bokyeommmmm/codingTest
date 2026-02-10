#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int start = 1;
    int end = 10;
    long long ans = 0;
    int len = 1;
    for (int i = 1; i <= N; i++)
    {
        if (i < end)
        {
            ans += len;
        }
        else
        {
            end *= 10;
            len++;
            ans += len;
        }
    }
    cout << ans;
    return 0;
}