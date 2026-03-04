#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int res;
vector<pair<int,int>> xy;
vector<int> visited;
int comx, comy, homex, homey;

void dfs(int cnt, int dist, int last) // last: 직전 위치(-1이면 회사)
{
    if (dist >= res) return; // 가지치기

    if (cnt == N)
    {
        // 마지막 손님 -> 집
        dist += abs(homex - xy[last].first) + abs(homey - xy[last].second);
        res = min(res, dist);
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (visited[i]) continue;

        visited[i] = 1;

        int add;
        if (last == -1) // 회사 -> 첫 손님
            add = abs(comx - xy[i].first) + abs(comy - xy[i].second);
        else            // 손님 -> 손님
            add = abs(xy[last].first - xy[i].first) + abs(xy[last].second - xy[i].second);

        dfs(cnt + 1, dist + add, i);

        visited[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        cin >> N;
        visited.assign(N, 0);
        xy.clear();
        xy.reserve(N);

        res = 2000000;

        cin >> comx >> comy >> homex >> homey;
        for (int i = 0; i < N; i++)
        {
            int x, y; cin >> x >> y;
            xy.push_back({x, y});
        }

        dfs(0, 0, -1);

        cout << "#" << tc << " " << res << "\n";
    }
    return 0;
}