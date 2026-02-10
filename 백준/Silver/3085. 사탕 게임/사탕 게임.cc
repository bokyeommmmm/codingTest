#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int calx(vector<vector<char>> &arr, int N)
{
    int res = 1;
    char now;
    for (int i = 0; i < N; i++)
    {
        int cnt = 1;
        for (int j = 0; j < N - 1; j++)
        {
            now = arr[i][j];
            if ((j < N - 1) && now == arr[i][j + 1])
            {
                cnt++;
            }
            else
            {
                cnt = 1;
            }
            res = max(cnt, res);
        }
    }

    return res;
}
int caly(vector<vector<char>> &arr, int N)
{
    int res = 1;
    char now;
    for (int i = 0; i < N; i++)
    {
        int cnt = 1;
        for (int j = 0; j < N - 1; j++)
        {
            now = arr[j][i];
            if ((j < N - 1) && now == arr[j + 1][i])
            {
                cnt++;
                res = max(cnt, res);
            }
            else
            {
                cnt = 1;
            }
            res = max(cnt, res);
        }
    }

    return res;
}

int func(vector<vector<char>> &a, int N)
{
    int ans = max(calx(a, N), caly(a, N)); // swap 안 해도 이미 연속 있을 수 있으니

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {

            // 오른쪽과 swap
            if (j + 1 < N && a[i][j] != a[i][j + 1])
            {
                char tmp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = tmp;

                ans = max(ans, max(calx(a, N), caly(a, N)));

                tmp = a[i][j];
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = tmp; // 원복
            }

            // 아래와 swap
            if (i + 1 < N && a[i][j] != a[i + 1][j])
            {
                char tmp = a[i][j];
                a[i][j] = a[i + 1][j];
                a[i + 1][j] = tmp;

                ans = max(ans, max(calx(a, N), caly(a, N)));

                tmp = a[i][j];
                a[i][j] = a[i + 1][j];
                a[i + 1][j] = tmp; // 원복
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<char>> arr(N, vector<char>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            char c;
            cin >> c;
            arr[i][j] = c;
        }
    }
    cout << func(arr, N);
    return 0;
}