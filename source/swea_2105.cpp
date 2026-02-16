#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, res;
int dr[4] = {1, 1, -1, -1};
int dc[4] = {1, -1, -1, 1};
vector<vector<int>> map;

bool dessert[101];
bool visited[25][25];

void dfs(int sr, int sc, int r, int c, int cnt, int diridx)
{
    if (diridx == 4)
        return;

    int nr = r + dr[diridx];
    int nc = c + dc[diridx];

    if (nr == sr && nc == sc && diridx == 3)
    {
        res = max(res, cnt);
        return;
    }

    if ((nr < 0 || nc < 0 || nr >= N || nc >= N))
        return;

    int d = map[nr][nc];

    if (visited[nr][nc])
        return;
    if (dessert[d])
        return;

    visited[nr][nc] = true;
    dessert[d] = true;

    dfs(sr, sc, nr, nc, cnt + 1, diridx);

    dfs(sr, sc, nr, nc, cnt + 1, diridx + 1);

    visited[nr][nc] = false;
    dessert[d] = false;
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
        map.assign(N, vector<int>(N, 0));
        res = -1;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < N - 2; i++)
        {
            for (int j = 1; j < N - 1; j++)
            {
                for (int k = 0; k < 101; k++)
                    dessert[k] = false;
                for (int x = 0; x < 25; x++)
                    for (int y = 0; y < 25; y++)
                        visited[x][y] = false;

                visited[i][j] = true;
                dessert[map[i][j]] = true;

                dfs(i, j, i, j, 1, 0);
            }
        }

        cout << "#" << tc << " " << res << "\n";
    }

    return 0;
}
