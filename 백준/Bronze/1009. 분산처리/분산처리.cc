#include<iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int a, b;
        cin >> a >> b;

        int res = 1;
        int num = a % 10;

        for (int i = 0; i < b; i++)
        {
            res = (res * num) % 10;
        }

        if (res == 0) cout << 10 << "\n";
        else cout << res << "\n";
    }

    return 0;
}