#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()

{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 1; tc <= 10; tc++)
    {
        stack<char> stk;
        int N;
        cin >> N;
        string str;
        cin >> str;
        string post_str;
        for (int i = 0; i < N; i++)
        {
            if (str[i] >= '0' && str[i] <= '9')
            {
                post_str += str[i];
            }
            else
            {
                if (str[i] == '+')
                {
                    while (!stk.empty() && stk.top() != '(' && (stk.top() == '*' || stk.top() == '+'))
                    {
                        post_str += stk.top();
                        stk.pop();
                    }
                    stk.push('+');
                }
                else if (str[i] == '*')
                {
                    while (!stk.empty() && stk.top() == '*')
                    {
                        post_str += stk.top();
                        stk.pop();
                    }
                    stk.push('*');
                }
                else if (str[i] == '(')
                {
                    stk.push('(');
                }
                else if (str[i] == ')')
                {
                    while (!stk.empty() && stk.top() != '(')
                    {
                        post_str += stk.top();
                        stk.pop();
                    }
                    stk.pop();
                }
            }
        }
        while (!stk.empty())
        {
            post_str += stk.top();
            stk.pop();
        }
        stack<int> res;
        for (int i = 0; i < post_str.size(); i++)
        {
            if (post_str[i] >= '0' && post_str[i] <= '9')
            {
                res.push((int)(post_str[i] - '0'));
            }
            else
            {
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                if (post_str[i] == '+')
                {
                    res.push(a + b);
                }
                else
                {
                    res.push(a * b);
                }
            }
        }
        cout << "#" << tc << " " << res.top() << "\n";
    }

    return 0;
}