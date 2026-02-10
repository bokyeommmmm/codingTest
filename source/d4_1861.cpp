#include <iostream>
#include <vector>
using namespace std;

int N;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int dfs(int x, int y, vector<vector<int>> &board)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (board[x][y] + 1 == board[nx][ny])
        {

            return 1 + dfs(nx, ny, board);
        }
    }
    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc = 0;
    cin >> tc;
    for (int test_case = 1; test_case <= tc; test_case++)
    {
        cin >> N;
        int max_cnt = 0;
        int start = 10000000;
        vector<vector<int>> board(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> board[i][j];
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int temp = dfs(i, j, board);
                if (temp > max_cnt)
                {
                    max_cnt = temp;
                    start = board[i][j];
                }
                else if (temp == max_cnt)
                {
                    if (board[i][j] < start)
                        start = board[i][j];
                }
            }
        }

        cout << "#" << test_case << " " << start << " " << max_cnt << "\n";
    }

    return 0;
}