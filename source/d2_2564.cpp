#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    vector<vector<int>> area(100, vector<int>(100));

    int n;
    cin >> n;
    int sol = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                area[i + x][j + y] = 1;
            }
        }
    }
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (area[i][j] == 1)
                sol++;
        }
    }
    cout << sol;
    return 0;
}
