#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int res = min(min(x, y), min(w - x, h - y));
    cout << res;

    return 0;
}