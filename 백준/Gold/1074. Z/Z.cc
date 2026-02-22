#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

int func(int r, int c, int N)
{
    if (N == 0)
    {
        return 0;
    }
    int quarter = pow(4, N - 1);
    int len = pow(2, N - 1);
    if (r < len && c < len)
    {
        return func(r, c, N-1);
    }
    else if (r < len && c >= len)
    {
        return quarter + func(r, c - len, N - 1);
    }
    else if (r >= len && c < len)
    {
        return quarter * 2 + func(r - len, c, N - 1);
    }
    else
    {
        return quarter * 3 + func(r - len, c - len, N - 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int SIZE = pow(2, N);
    int r, c;
    cin >> r >> c;
    cout << func(r, c, N);
}
