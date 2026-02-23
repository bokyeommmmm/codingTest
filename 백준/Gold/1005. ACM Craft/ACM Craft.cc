#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K, dest;

vector<int> D;
vector<vector<int>> graph;
vector<vector<int>> required;

vector<int> visited;
queue<int> q;
int maxtime;
bool can_build(int num)
{
    maxtime = 0;
    for (int i = 0; i < required[num].size(); i++)
    {
        maxtime = max(visited[required[num][i]], maxtime);
        if (visited[required[num][i]] == 0) // 하나라도 필요건물 안지어지면
        {
            return false;
        }
    }
    return true;
}
void bfs()
{
    while (!q.empty())
    {
        int from = q.front();
        q.pop();
        if (from == dest)
        {
            return;
        }
        for (int i = 0; i < graph[from].size(); i++)
        {
            int to = graph[from][i];
            if (visited[to] != 0)
                continue;
            if (can_build(to))
            {
                visited[to] = D[to] + maxtime;
                q.push(to);
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
    for (int tc = 0; tc < T; tc++)
    {

        cin >> N >> K;
        D.clear();
        D.push_back(0);
        while (!q.empty())
        {
            q.pop();
        }

        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            D.push_back(temp);
        }
        graph.assign(N + 1, vector<int>());
        required.assign(N + 1, vector<int>());
        visited.assign(N + 1, 0);
        for (int i = 0; i < K; i++)
        {
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            required[to].push_back(from);
        }
        cin >> dest;

        for (int i = 1; i < N + 1; i++) // 선수과목 없는것부터 가보자.
        {
            if (required[i].size() == 0)
            {
                visited[i] = D[i];
                q.push(i);
            }
        }
        bfs();
        cout << visited[dest] << "\n";
    }

    return 0;
}