#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, maxCnt;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void dfs(int x, int y, int cnt, vector<vector<char>> &map, int mask)
{
    cnt++;
    maxCnt = max(maxCnt, cnt);

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= R || ny >= C)
            continue;

        int idx = map[nx][ny] - 'A';
        int bit = (1 << idx);

        if (mask & bit)
            continue;

        dfs(nx, ny, cnt, map, mask | bit);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;

    vector<vector<char>> map(R, vector<char>(C, '.'));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> map[i][j];
        }
    }

    int startIdx = map[0][0] - 'A';
    int startMask = (1 << startIdx);

    dfs(0, 0, 0, map, startMask);

    cout << maxCnt;
    return 0;
}
