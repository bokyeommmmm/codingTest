#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (!pq.empty() && a == 0)
        {
            cout << pq.top() << "\n";
            pq.pop();
        }
        else if (pq.empty() && a == 0)
        {
            cout << 0 << "\n";
        }
        else
            pq.push(a);
    }
}