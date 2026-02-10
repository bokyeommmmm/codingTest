#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> func(vector<char> &arr, int W)
{
    vector<int> sol(W, -1);

    for (int i = 0; i < W; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            if (arr[j] == 'c')
            {
                sol[i] = i - j;
                break;
            }
        }
    }

    return sol;
}
int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int W, H;
    cin >> H >> W;

    vector<vector<int>> sol;
    for (int i = 0; i < H; i++)
    {
        vector<char> arr;
        for (int j = 0; j < W; j++)
        {
            char temp;
            cin >> temp;
            arr.push_back(temp);
        }
        sol.push_back(func(arr, W));
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}