#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, res;
vector<vector<int>> board;

int main()
{
    cin >> N;
    board.assign(N, vector<int>(N));
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= N - 3; j++)
        {
            int sum1 = board[i][j] + board[i][j + 1] + board[i][j + 2];

            for (int k = i; k < N; k++)
            {
                int start;
                if (k == i) start = j + 3; 
                else start = 0;            

                for (int l = start; l <= N - 3; l++)
                {
                    int sum2 = board[k][l] + board[k][l + 1] + board[k][l + 2];
                    res = max(res, sum1 + sum2);
                }
            }
        }
    }

    cout << res;
    return 0;
}