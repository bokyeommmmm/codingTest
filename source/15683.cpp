#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> CCTV; // CCTV 좌표
vector<vector<int>> map;
vector<int> dir;
void scan(vector<vector<int>> map)
{
    int s = CCTV.size();
    for (int i = 0; i < s; i++)
    {
        int x = CCTV[i].first;
        int y = CCTV[i].second;
        if (map[x][y] == 1) // 1번 cctv일때.
        {
            if (dir[i] == 0)
            {
                while (true)
                {
                    int x = x + 1;
                    int y = y;
                    if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] != 6)
                        break;
                    if (map[x][y] >= 1 && map[x][y] <= 5)
                        continue;
                    map[x][y] = 7;
                }
            }
            if (dir[i] == 1)
            {
                while (true)
                {
                    int x = x - 1;
                    int y = y;
                    if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] != 6)
                        break;
                    if (map[x][y] >= 1 && map[x][y] <= 5)
                        continue;
                    map[x][y] = 7;
                }
            }
            if (dir[i] == 2)
            {
                while (true)
                {
                    int x = x;
                    int y = y + 1;
                    if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] != 6)
                        break;
                    if (map[x][y] >= 1 && map[x][y] <= 5)
                        continue;
                    map[x][y] = 7;
                }
            }
            if (dir[i] == 3)
            {
                while (true)
                {
                    int x = x;
                    int y = y - 1;
                    if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] != 6)
                        break;
                    if (map[x][y] >= 1 && map[x][y] <= 5)
                        continue;
                    map[x][y] = 7;
                }
            }
        }
        if (map[x][y] == 3) // 1번 cctv일때.
        {
            if (dir[i] == 0)
            {
                while (true)
                {
                    int x = x + 1;
                    int y = y+1;
                    if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] != 6)
                        break;
                    if (map[x][y] >= 1 && map[x][y] <= 5)
                        continue;
                    map[x][y] = 7;
                }
            }
            if (dir[i] == 1)
            {
                while (true)
                {
                    int x = x - 1;
                    int y = y-1;
                    if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] != 6)
                        break;
                    if (map[x][y] >= 1 && map[x][y] <= 5)
                        continue;
                    map[x][y] = 7;
                }
            }
            if (dir[i] == 2)
            {
                while (true)
                {
                    int x = x-1;
                    int y = y + 1;
                    if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] != 6)
                        break;
                    if (map[x][y] >= 1 && map[x][y] <= 5)
                        continue;
                    map[x][y] = 7;
                }
            }
            if (dir[i] == 3)
            {
                while (true)
                {
                    int x = x+1;
                    int y = y - 1;
                    if (x < 0 || y < 0 || x >= N || y >= M || map[x][y] != 6)
                        break;
                    if (map[x][y] >= 1 && map[x][y] <= 5)
                        continue;
                    map[x][y] = 7;
                }
            }
        }
    }
}
void ferm(int idx)
{
    if (idx == CCTV.size())
    {
        scan(map);
        return;
    }
    else
    {
        dir[idx] = 0;
        ferm(idx + 1);
        dir[idx] = 1;
        ferm(idx + 1);
        dir[idx] = 2;
        ferm(idx + 1);
        dir[idx] = 3;
        ferm(idx + 1);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    int temp;
    map.assign(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) // 맵 생성 및 cctv 좌표
        {
            cin >> temp;
            map[i][j] = temp;
            if (temp >= 1 && temp <= 5)
                CCTV.push_back({i, j});
        }
    }
    dir.assign(CCTV.size(), 0); // 일단 다 0방향인게 기본값.
    ferm(0);

    return 0;
}