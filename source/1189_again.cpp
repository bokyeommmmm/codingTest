#include <iostream>
#include <vector>
#include <string>
using namespace std;

int R, C, K;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int answer = 0;
void dfs(int x, int y, int cnt, vector<vector<char>> &map, vector<vector<bool>> &visited)
{
    if (cnt > K)
        return;

    if (x == 0 && y == C - 1)
    {
        if (cnt == K)
            answer++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= R || ny >= C)
            continue;
        if (map[nx][ny] == 'T')
            continue;
        if (visited[nx][ny])
            continue;

        visited[nx][ny] = true;
        dfs(nx, ny, cnt + 1, map, visited);
        visited[nx][ny] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C >> K;
    vector<vector<char>> map(R, vector<char>(C, '.'));
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
        {
            map[i][j] = s[j];
        }
    }
    visited[R - 1][0] = true;
    dfs(R - 1, 0, 1);

    cout << answer;

    return 0;
}