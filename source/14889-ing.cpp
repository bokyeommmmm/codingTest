#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> S(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int temp;
            cin >> temp;
            S[i][j] = temp;
        }
    }
    int min_gap = 10000;

    vector<int> team(N);
    for (int i = 0; i < N / 2; i++)
    {
        team[i] = 1; // 일단 앞 절반이 같은팀
    }
    for (int i = 0; i < N / 2; i++)
    {
        int x = N / 2 - i - 1;
        int y = x + 1;
        for (int j = 0; j < N / 2; j++)
        {
            int scoreA = 0;
            int scoreB = 0;
            for (int k = 0; k < N - 1; k++)
            {
                for (int l = k + 1; l < N; l++)
                {
                    if (team[k] == 1 && team[l] == 1)
                    {
                        scoreA = scoreA + S[k][l] + S[l][k];
                    }
                    if (team[k] == 0 && team[l] == 0)
                    {
                        scoreB = scoreB + S[k][l] + S[l][k];
                    }
                }
            }
            min_gap = min(min_gap, abs(scoreA-scoreB));

            team[x + j]--;
            team[y + j]++;
        }
    }
    cout << min_gap;

    return 0;
}