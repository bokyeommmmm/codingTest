#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
 
using namespace std;
 
int N;
int min_val = 1000000000;
int max_val = -1000000000;
int sign_cnt[4] = { 0, 0, 0, 0 }; //+ - * %/
stack<int> cur_val;             // 누적하면서 쌓을 값.
 
int calc(int num, int num2, int idx)
{
    if (idx == 0)
    {
        return num + num2;
    }
    else if (idx == 1)
    {
        return num - num2;
    }
    else if (idx == 2)
    {
        return num * num2;
    }
    else if (idx == 3)
    {
        return num / num2;
    }
}
void dfs(vector<int> &num, int cnt)
{
    if (cnt == N - 1) // 뭐 기호 다 쌓았으면 계산해보자잉.
    {
        min_val = min(min_val, cur_val.top());
        max_val = max(max_val, cur_val.top());
    }
 
    if (sign_cnt[0] > 0)
    {
        cur_val.push(calc(cur_val.top(), num[cnt + 1], 0));
        sign_cnt[0]--;
        dfs(num, cnt + 1);
        cur_val.pop();
        sign_cnt[0]++;
    }
    if (sign_cnt[1] > 0)
    {
        cur_val.push(calc(cur_val.top(), num[cnt + 1], 1));
        sign_cnt[1]--;
        dfs(num, cnt + 1);
        cur_val.pop();
        sign_cnt[1]++;
    }
    if (sign_cnt[2] > 0)
    {
        cur_val.push(calc(cur_val.top(), num[cnt + 1], 2));
        sign_cnt[2]--;
        dfs(num, cnt + 1);
        cur_val.pop();
        sign_cnt[2]++;
    }
    if (sign_cnt[3] > 0)
    {
        cur_val.push(calc(cur_val.top(), num[cnt + 1], 3));
        sign_cnt[3]--;
        dfs(num, cnt + 1);
        cur_val.pop();
        sign_cnt[3]++;
    }
    return;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        while (!cur_val.empty())
        {
            cur_val.pop();
        }
        min_val = 1000000000;
        max_val = -1000000000;
 
        cin >> N;
 
        vector<int> num;
 
        for (int i = 0; i < 4; i++)
        {
            cin >> sign_cnt[i]; // 각 기호 숫자 세고.
        }
        for (int i = 0; i < N; i++) // 숫자배열.
        {
            int temp;
            cin >> temp;
            num.push_back(temp);
        }
 
        cur_val.push(num[0]); // 일단 얜 고정.
 
        dfs(num, 0); // ㄱㄱ
 
        cout << "#" << tc << " " << max_val - min_val << "\n";
    }
 
    return 0;
}