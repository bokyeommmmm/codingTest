#include <iostream>
#include <vector>
using namespace std;

int N, T;
vector<int> arr;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    arr.push_back(-1);
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int a, b;
        cin >> a >> b;

        if (a == 1)
        {
            for (int i = b; i <= N; i = i + b)
            {
                if (arr[i] == 1)
                    arr[i] = 0;
                else if (arr[i] == 0)
                    arr[i] = 1;
            }
        }
        else if (a == 2)
        {
            if (arr[b] == 1)
                arr[b] = 0;
            else if (arr[b] == 0)
                arr[b] = 1;
            int c = 1;

            while (true)
            {
                if (b - c < 1 || b + c > N || (arr[b - c] != arr[b + c]))
                    break;
                if (arr[b - c] == arr[b + c])
                {
                    if (arr[b - c] == 0)
                    {
                        arr[b + c] = 1;
                        arr[b - c] = 1;
                    }
                    else
                    {
                        arr[b + c] = 0;
                        arr[b - c] = 0;
                    }
                }
                c++;
            }
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << " ";
        if (i % 20 == 0)
            cout << "\n";
    }

    return 0;
}