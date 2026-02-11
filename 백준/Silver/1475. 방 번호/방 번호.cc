#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    int num[10] = {0};

    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '6')
        {
            num[9]++;
        }
        else
            num[input[i] - '0']++;
    }
    num[9] = (num[9] + 1) / 2;
    int maxval = 0;
    for (int i = 0; i < 10; i++)
    {
        maxval = max(maxval, num[i]);
    }

    cout << maxval;
}
