#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        string str;
        getline(cin, str);
        if (str == ".")
            return 0;
        stack<char> stk;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '.')
            {
                if (stk.empty())
                {
                    cout << "yes\n";
                }
                else
                {
                    cout << "no\n";
                }
            }
            else if (str[i] == '(')
            {
                stk.push('(');
            }
            else if (str[i] == '[')
            {
                stk.push('[');
            }
            else if (str[i] == ')')
            {
                if (!stk.empty() && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    cout << "no\n";
                    break;
                }
            }
            else if (str[i] == ']')
            {
                if (!stk.empty() && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    cout << "no\n";
                    break;
                }
            }
        }
    }
    return 0;
}
