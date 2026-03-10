#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, res;
vector<vector<int>> board;
vector<pair<int, int>> home;
vector<pair<int, int>> chicken;
vector<vector<int>> dist;
vector<int> arr; // 치킨 집 인덱스들 담김 .

void calc()
{
    int sum = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        int nearest = 1000000;
        for (int j = 0; j < arr.size(); j++)
        {
            nearest = min(nearest, dist[i][arr[j]]);
        }
        sum += nearest;
    }
    res = min(res, sum);
}
void dfs(int idx, int cnt)
{
    if (idx == chicken.size())
    {
        if (cnt == M)
        {
            calc();
        }
        return;
    }
    arr.push_back(idx);
    dfs(idx + 1, cnt + 1);
    arr.pop_back();
    dfs(idx + 1, cnt);
}
int main()
{
    cin >> N >> M;
    board.assign(N, vector<int>(N));
    res = 100000000;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                home.push_back({i, j});
            }
            else if (temp == 2)
            {
                chicken.push_back({i, j});
            }
        }
    }
    dist.assign(home.size(), vector<int>(0));
    for (int i = 0; i < home.size(); i++)
    {
        for (int j = 0; j < chicken.size(); j++)
        {
            int d = (abs(home[i].first - chicken[j].first) + abs(home[i].second - chicken[j].second));
            dist[i].push_back(d);
        }
    }

    dfs(0, 0);
    cout << res;
    return 0;
}