#include <iostream>
#include <algorithm>
using namespace std;

int T;
int price[4], plan[13];
int res;

void dfs(int month, int sum)
{
    if (sum >= res) return;

    if (month >= 12) {
        res = min(res, sum);
        return;
    }
    
    int cost1 = min(plan[month + 1] * price[0], price[1]);
    dfs(month + 1, sum + cost1);

    dfs(month + 3, sum + price[2]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;

    for (int tc = 1; tc <= T; tc++)
    {
        for (int i = 0; i < 4; i++) cin >> price[i];
        for (int i = 1; i <= 12; i++) cin >> plan[i];

        res = price[3];

        dfs(0, 0);

        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}
