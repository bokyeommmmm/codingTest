#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, B, res;
vector<int> H;

void dfs(int sum, int idx)
{
    if (sum >= B)
    {
        res = min(res, sum - B);
        return;
    }
    if (idx == N)
        return;

    dfs(sum + H[idx], idx + 1);
    dfs(sum, idx + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N >> B;
        int temp;
        res = 100000000;
        H.clear();
        for (int i = 0; i < N; i++)
        {
            cin >> temp;

            H.push_back(temp);
        }
        sort(H.begin(), H.end(), greater<int>());

        dfs(0, 0);

        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}
