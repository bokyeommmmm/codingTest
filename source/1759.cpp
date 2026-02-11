#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int N;
int xx,yy;
vector<vector<int>> map;
vector<vector<int>> visited;
set<pair<pair<int, int>,pair<int,int>>> res;

int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};

void func3()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == 0)
            {
                res.insert({{xx,yy},{i, j}});
            }
        }
    }
}

void func2(int x, int y)
{

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= N)
            continue;
        if (visited[nx][ny] == 1)
            continue;
        visited[nx][ny] = 1;
        map[nx][ny] = 1;
    }
    func3();
}

void func()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
                map.assign(N, vector<int>(N, 0));
                visited.assign(N, vector<int>(N, 0));
                visited[i][j] = 1;
                map[i][j] = 1; // 전체 순회하며 일단 첫 퀸 놓고
                xx=i;
                yy=j;
                func2(i, j);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    func();

    cout << res.size();
    return 0;
}