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
        int a;
        cin >> a;
        int res1 = 0;
        int res2 = 0;
        int res3 = 0;
        int res4 = 0;
        int max_res = 0;
        vector<vector<int>> ladder(100, vector<int>(100, 0));
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                cin >> ladder[i][j];
            }
        }

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
               res1+=ladder[i][j];
               res2+=ladder[j][i];
            }
            max_res=max(max_res,max(res1,res2));
            res1=0;
            res2=0;
            res3+=ladder[i][i];
            res4+=ladder[i][99-i];
        }
        max_res=max(max_res,max(res3,res4));

        cout << "#" << tc << " " << max_res << "\n";
    }

    return 0;
}