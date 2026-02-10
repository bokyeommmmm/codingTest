#include <iostream>

using namespace std;
int t[1001];

int tile(int x)
{
    if (x == 1)
        return t[x] = 1;
    if (x == 2)
        return t[x] = 2;
    if (t[x] != 0)
        return t[x];
    return t[x] = (tile(x - 1) + tile(x - 2)) % 10007;
}
int main()
{
    int n;
    cin >> n;
    int result = tile(n);
    cout << result;
    return 0;
}