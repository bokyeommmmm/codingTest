#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, res;
int dirr[4] = {0, 1, 0, -1};
int dirc[4] = {1, 0, -1, 0}; // 우 하 좌 상

vector<vector<int>> board;
vector<vector<pair<int, int>>> whitehole;

void dfs(int sr, int sc, int r, int c, int score, int dir)
{
    while (true)
    {
        int nr = r + dirr[dir];
        int nc = c + dirc[dir];

        // 벽
        if (nr < 0 || nc < 0 || nr >= N || nc >= N)
        {
            dir = (dir + 2) % 4;
            score++;
            continue;
        }

        int next = board[nr][nc];

        if (next == -1 || (nr == sr && nc == sc)) // 블랙홀이거나 시작점
        {
            res = max(res, score);
            return;
        }

        // 이동 확정
        r = nr;
        c = nc;

        // 블록 5
        if (next == 5)
        {
            dir = (dir + 2) % 4;
            score++;
        }
        // 블록 1~4
        else if (next >= 1 && next <= 4)
        {
            if (next == 1)
            {
                if (dir == 0)
                    dir = 2; // 우 -> 좌
                else if (dir == 1)
                    dir = 0; // 하 -> 우
                else if (dir == 2)
                    dir = 3; // 좌 -> 상
                else if (dir == 3)
                    dir = 1; // 상 -> 하
            }
            else if (next == 2)
            {
                if (dir == 0)
                    dir = 2; // 우 -> 좌
                else if (dir == 1)
                    dir = 3; // 하 -> 상
                else if (dir == 2)
                    dir = 1; // 좌 -> 하
                else if (dir == 3)
                    dir = 0; // 상 -> 우
            }
            else if (next == 3)
            {
                if (dir == 0)
                    dir = 1; // 우 -> 하
                else if (dir == 1)
                    dir = 3; // 하 -> 상2
                else if (dir == 2)
                    dir = 0; // 좌 -> 우
                else if (dir == 3)
                    dir = 2; // 상 -> 좌
            }
            else if (next == 4)
            {
                if (dir == 0)
                    dir = 3; // 우 -> 상
                else if (dir == 1)
                    dir = 2; // 하 -> 좌
                else if (dir == 2)
                    dir = 0; // 좌 -> 우
                else if (dir == 3)
                    dir = 1; // 상 -> 하
            }
            score++;
        }

        // 웜홀
        else if (next >= 6 && next <= 10)
        {

            if (whitehole[next].size() == 2)
            {
                if (whitehole[next][0].first == r && whitehole[next][0].second == c)
                {
                    r = whitehole[next][1].first;
                    c = whitehole[next][1].second;
                }
                else
                {
                    r = whitehole[next][0].first;
                    c = whitehole[next][0].second;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N;
        board.assign(N, vector<int>(N, 0));
        res = 0;

        whitehole.assign(11, vector<pair<int, int>>());

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                int temp;
                cin >> temp;
                board[i][j] = temp;
                if (temp >= 6 && temp <= 10)
                {
                    whitehole[temp].push_back({i, j});
                }
            }
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (board[i][j] == 0)
                {
                    for (int d = 0; d < 4; d++)
                    {
                        dfs(i, j, i, j, 0, d);
                    }
                }
            }
        }

        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}
