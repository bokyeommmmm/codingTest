#include <iostream>
#include <stack>
#include <string>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        string str;
        cin >> str;
        int cnt = 0;
        int tell=0;
        for (int j = 0; j < str.length(); j++)
        {
            if (str[j] == '(')
            {
                cnt++;
            }
            else
                cnt--;
            if (cnt < 0)
            {
                cout << "NO\n";
                tell++;
                break;
            }
        }
        if (cnt == 0&& tell==0)
        {
            cout << "YES\n";
        }
        else if(cnt!=0&&tell==0)
            cout << "NO\n";
    }

    return 0;
}