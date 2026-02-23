#include <iostream>

#include <vector>

#include <queue>

#include <algorithm>
using namespace std;

int N, res, m;
vector<vector<int>> graph;
vector<vector<int>> history;
vector<int> visited;
queue<int> q;

bool can_gradu()
{
    int sum = 0;
    for (int i = 0; i < visited.size(); i++)
    {
        if (visited[i] == 0)
            return false;
    }
    return true;
}
bool can_take(int to) // 수업 들을 수 있는지
{
    for (int i = 0; i < history[to].size(); i++)
    {
        int cl = history[to][i]; // 갈 과목의 선수과목마다,
        if (visited[cl] == 0)    // 못들은것이 있으면 false;
            return false;
    }
    return true;
}
int get_dist(int to)
{
    m = 0;
    for (int i = 0; i < history[to].size(); i++)
    {

        int cl = history[to][i]; // 갈 과목의 선수과목마다,

        m = max(m, visited[cl]); // 가장 최근에 들은 것의 다음학기에 듣자.
    }
    return (m + 1);
}
void bfs()
{
    while (!q.empty())
    {

        int from = q.front();
        q.pop();

        if (can_gradu())
        {
            res = visited[from];
            return;
        }
        for (int i = 0; i < graph[from].size(); i++)
        {
            int to = graph[from][i];

            if (!can_take(to)) // 선수과목 다 안들었으면
                continue;
            if (visited[to] > 0) // 이미 들었으면
                continue;
            visited[to] = get_dist(to);
            q.push(to);
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
        cin >> N;                                 // 과목 수
        graph.assign(N + 1, vector<int>());       //[from][to~]
        history.assign(N + 1, vector<int>(0, 0)); //[to][from]
        visited.assign(N + 1, 0);
        visited[0] = 1;
        while (!q.empty())
        {
            q.pop();
        }
        bool ok = false;
        res = -1;

        for (int i = 1; i <= N; i++)
        {
            int num;
            cin >> num;   // 선수과목 수.
            if (num == 0) // 선수과목이 없는애들로 1학기 시작.
            {
                visited[i] = 1;
                q.push(i);
            }
            for (int j = 0; j < num; j++)
            {
                int from;
                cin >> from;
                graph[from].push_back(i);
                history[i].push_back(from); // i번 과목의 수강 선수과목들
            }
        }
        bfs();
        cout << "#" << tc << " " << res << "\n";
    }
    return 0;
}