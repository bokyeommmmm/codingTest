#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    bool fel = true;
    for (int i = 0; i < input.length() / 2; i++)
    {
        if (input[i] != input[input.length() - 1 - i])
            fel = false;
    }
    if (fel)
    {
        cout << 1;
    }
    else
        cout << 0;

    return 0;
}
