#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;
    vector<int> res(10);

    int temp = a * b * c;

    while (temp > 0)
    {
        res[temp % 10]++;
        temp /= 10;
    }
    for (int i = 0; i < 10; i++)
    {
        cout << res[i] << "\n";
    }
}