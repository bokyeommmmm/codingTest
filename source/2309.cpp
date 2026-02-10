#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr;
    int sum=0;
    for (int i = 0; i < 9; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    for (int i = 0; i < 9; i++)
    {
        sum += arr[i];
    }
    int over = sum - 100;

    int idx1, idx2;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < 8; i++)
    {
        for (int j = i+1; j < 9; j++)
        {
            if (arr[i] + arr[j] == over)
            {
                idx1 = i;
                idx2 = j;
            }
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (i != idx1 && i != idx2)
            cout << arr[i] << "\n";
    }

    return 0;
}