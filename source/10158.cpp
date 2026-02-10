#include <iostream>
#include <vector>
using namespace std;

int func(int p, int t, int W)
{
    vector<int> arr;
    for (int j = 0; j < 2; j++)
    {
        for (int i = 0; i < W; i++)
        {
            arr.push_back(i);
        }
        for (int i = W; i > 0; i--)
        {
            arr.push_back(i);
        }
    }
    return arr[p + (t % (W * 2))];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int W, H;
    cin >> W >> H;
    int p, q;
    cin >> p >> q;
    int t;
    cin >> t;
    cout << func(p, t, W) << " " << func(q, t, H);
    return 0;
}
