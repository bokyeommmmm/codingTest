#include <iostream>
using namespace std;

int main()
{
    long long A, B, V;
    cin >> A >> B >> V;


    if (A >= V)
    {
        cout << 1;
        return 0;
    }

    long long oneDay = A - B;         
    long long answer = (V - B - 1) / oneDay + 1;


    cout << answer;
    return 0;
}
