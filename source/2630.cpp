#include <iostream>
#include <vector>
using namespace std;

int blue = 0;
int white = 0;

void func(vector<vector<int>> &a, int si, int sj, int n)
{
    if (n == 1)
    {
        if (a[si][sj] == 1) blue++;
        else white++;
        return;
    }

    int sum = 0;
    for (int i = si; i < si + n; i++)
        for (int j = sj; j < sj + n; j++)
            sum += a[i][j];

    if (sum == 0)
    {
        white++;
        return;
    }
    if (sum == n * n)
    {
        blue++;
        return;
    }

    int half = n / 2;
    func(a, si, sj, half);
    func(a, si, sj + half, half);
    func(a, si + half, sj, half);
    func(a, si + half, sj + half, half);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> a(N, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> a[i][j];

    func(a, 0, 0, N);

    cout << white << "\n" << blue;
    return 0;
}
