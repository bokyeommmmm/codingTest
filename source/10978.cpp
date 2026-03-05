#include <iostream>
#include <string>

using namespace std;

bool isDesc(int n)
{
    string str = to_string(n);
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] - '0' <= str[i + 1] - '0')
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int cnt = 0;
    int num = 0;
    if (N < 10)
    {
        cout << N;
        return 0;
    }

    else
    {
        while (cnt < N)
        {
            num++;
            if (isDesc(num))
            {
                cnt++;
            }
            if (num == 1000000000)
            {
                cout << -1;
                return 0;
            }
        }
    }
    cout << num;

    return 0;
}