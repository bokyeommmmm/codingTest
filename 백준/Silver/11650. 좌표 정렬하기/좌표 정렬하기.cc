#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    vector<pair<int, int>> arr;
    for (int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        arr.push_back({x, y});
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++)
    {
        cout << arr[i].first << " " << arr[i].second << "\n";
    }

    return 0;
}
