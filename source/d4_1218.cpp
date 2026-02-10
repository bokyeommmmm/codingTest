#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 1; tc <= 10; tc++)
    {
        int N;
        cin >> N;
        stack<char> s;
        int res = 1;
        for (int i = 0; i < N; i++)
        {
            char c;
            cin >> c;
            if (c == '(' || c == '[' || c == '<' || c == '{') // 여는건 ㅇㅋ
                s.push(c);
            else
            {
                if (s.empty())
                {
                    res = 0;
                }
                else
                {
                    char t = s.top();
                    if ((c == ')' && t == '(') ||
                        (c == ']' && t == '[') ||
                        (c == '}' && t == '{') ||
                        (c == '>' && t == '<'))
                    {
                        s.pop();
                    }
                    else
                    {
                        res = 0;
                    }
                }
            }
        }
        if (!s.empty())
            res = 0;
        cout << '#' << tc << " " << res << "\n";
    }

    return 0;
}