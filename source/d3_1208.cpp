#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 1; tc <= 10; tc++)
    {
        vector<int> h(100);
        int dump;
        cin >> dump;
        for (int i = 0; i < 100; i++)
            cin >> h[i];

        for (int i = 0; i < dump; i++)
        {
            sort(h.begin(), h.end());
            h[0]++;
            h[99]--;
        }
        sort(h.begin(), h.end());

        cout << "#" << tc << " " << h[99] - h[0] << "\n";
    }
    return 0;
}
