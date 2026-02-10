#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int func(vector<vector<char>> &arr, int N, int M)
{

    char now;
    int res = 64;
    int cnt = 0;
    for (int i = 0; i + 7 < N; i++)
    {
        for (int j = 0; j + 7 < M; j++)
        {
            char now = arr[i][j];
            cnt = 0;
            for (int k = i; k < i + 8; k++)
            {
                for (int l = j; l < j + 8; l++)
                {
                    if ((k + l) % 2 == 0 && now != arr[k][l])
                    {
                        cnt++;
                    }
                    else if ((k + l) % 2 == 1 && now == arr[k][l])
                    {
                        cnt++;
                    }
                }
            }
            res = min(res, min(cnt, 64 - cnt));
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    vector<vector<char>> arr(N, vector<char>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c;
        }
    }
    cout << func(arr, N, M);
    return 0;
}