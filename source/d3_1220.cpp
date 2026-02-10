#include <vector>
#include <iostream>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 1; tc <= 10; tc++)
    {
        int N;
        cin >> N;
        int res = 0;
        vector<vector<int>> table(100, vector<int>(100, 0));

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                cin >> table[i][j];
            }
        }
        for (int j = 0; j < 100; j++)
        {
            int cnt = 0;
            for (int i = 0; i < 100; i++)
            {
                if (cnt == 0 && table[i][j] == 1)
                {
                    cnt++;
                }
                if (cnt == 1 && table[i][j] == 2)
                {
                    res++;
                    cnt = 0;
                }
            }
        }

        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}