#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, X;
int res;
vector<vector<int>> board;
vector<vector<int>> origin;

vector<int> visited;
set<pair<int, int>> candidate;

bool check_col(int row)
{
    for (int j = 0; j < N - 1; j++)
    {
        if (abs(board[j][row] - board[j + 1][row]) > 1)
        {
            return false;
        }
    }
    return true;
}

void col_dfs(int row)
{
    if (check_col(row))
    {
        visited.assign(N, 0);
        col_dfs(row + 1);
        res++;
        return;
    }
    for (int j = 0; j < N - 1; j++)
    {
        if (board[j][row] == board[j + 1][row]) // 평탄한 길이 2 이상이면 싸그리 다 후보.
        {
            candidate.insert({j, j + 1});
        }
    }
    for (int j = 0; j < N - 1; j++)
    {
        if (candidate.find({j, j + 1}) != candidate.end() && visited[j] == 0 && visited[j + 1] == 0) // 후보에 있고 안가봤으면
        {
            visited[j] = 1;
            visited[j + 1] = 1;
            board[j][row]++;
            col_dfs(row);
            board[j][row]--;
            board[j + 1][row]++;
            col_dfs(row);
            board[j + 1][row]--;
            visited[j] = 0;
            visited[j + 1] = 0;
        }
    }
    candidate.clear();
}

bool check_row(int col)
{
    for (int j = 0; j < N - 1; j++)
    {
        if (abs(board[col][j] - board[col][j + 1]) > 1)
        {
            return false;
        }
    }
    return true;
}

void row_dfs(int col)
{
    if (check_row(col))
    {
        visited.assign(N, 0);
        row_dfs(col + 1);
        res++;
        return;
    }
    for (int j = 0; j < N - 1; j++)
    {
        if (board[col][j] == board[col][j + 1]) // 평탄한 길이 2 이상이면 싸그리 다 후보.
        {
            candidate.insert({j, j + 1});
        }
    }
    for (int j = 0; j < N - 1; j++)
    {
        if (candidate.find({j, j + 1}) != candidate.end() && visited[j] == 0 && visited[j + 1] == 0) // 후보에 있고 안가봤으면
        {
            visited[j] = 1;
            visited[j + 1] = 1;
            board[col][j]++;
            row_dfs(col);
            board[col][j]--;
            board[col][j + 1]++;
            row_dfs(col);
            board[col][j + 1]--;
            visited[j] = 0;
            visited[j + 1] = 0;
        }
    }
    candidate.clear();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N >> X;
        origin.assign(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> origin[i][j];
            }
        }
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                origin[i][j] *= 2;
            }
        }
        auto board = origin;
        visited.assign(N, 0);
        row_dfs(0);
        board = origin;
        visited.assign(N, 0);
        col_dfs(0);
        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}