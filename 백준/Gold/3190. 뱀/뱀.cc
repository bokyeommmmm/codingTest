#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 오른, 아래, 왼, 위
int dirx[4] = {0, 1, 0, -1};
int diry[4] = {1, 0, -1, 0};

bool checkAndMove(vector<vector<int>> &arr,
                  queue<pair<int, int>> &snake,
                  int N,
                  int &x, int &y,
                  int dir)
{
    int nextx = x + dirx[dir];
    int nexty = y + diry[dir];

    // 벽박고죽음
    if (nextx < 0 || nextx >= N || nexty < 0 || nexty >= N)
    {
        return false;
    }

    bool isApple = (arr[nextx][nexty] == 1);

    if (arr[nextx][nexty] == 2)
        return false;

    if (!isApple)
    {
        pair<int, int> tail = snake.front();
        snake.pop();
        arr[tail.first][tail.second] = 0;
    }

    // 머리 가고
    snake.push(make_pair(nextx, nexty));
    arr[nextx][nexty] = 2;

    // ㄹㅇ이동 다음연산을위한거임사실
    x = nextx;
    y = nexty;

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> arr(N, vector<int>(N, 0));

    int K;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int r, c;
        cin >> r >> c;
        arr[r - 1][c - 1] = 1; // 1 사과
    }

    int L;
    cin >> L;
    queue<pair<int, char>> plan;
    for (int i = 0; i < L; i++)
    {
        int X;
        char C;
        cin >> X >> C;
        plan.push(make_pair(X, C));
    }

    int dir = 0;
    int time_ = 0;
    int x = 0, y = 0;

    queue<pair<int, int>> snake;
    snake.push(make_pair(x, y));
    arr[x][y] = 2;

    while (true)
    {
        time_++;

        if (!checkAndMove(arr, snake, N, x, y, dir))
        {
            cout << time_;
            return 0;
        }

        // 방향 전환 (이동 후, 해당 시간에 맞추어 회전)
        if (!plan.empty() && plan.front().first == time_)
        {
            char d = plan.front().second;
            plan.pop();
            if (d == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
        }
    }
}
