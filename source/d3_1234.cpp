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
        stack<char> s;

        int N;
        cin >> N;
        string temp;
        cin >> temp;
        for (int i = 0; i < N; i++)
        {

            if (!s.empty() && s.top() == temp[i])
                s.pop();
            else
                s.push(temp[i]);
        }
        stack<char> tmp;
        while (!s.empty())
        {
            tmp.push(s.top());
            s.pop();
        }

        cout << '#' << tc << " ";
        while (!tmp.empty())
        {
            cout << tmp.top();
            tmp.pop();
        }
        cout << "\n";
    }
    return 0;
}