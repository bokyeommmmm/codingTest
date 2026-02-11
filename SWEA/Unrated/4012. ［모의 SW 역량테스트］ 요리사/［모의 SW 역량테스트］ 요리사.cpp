#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<vector<int>> S;
vector<bool> is_team_a;
int res;
void calc() {
	int sum_a = 0;
	int sum_b = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (is_team_a[i] == true&&is_team_a[i]==is_team_a[j])
			{
				sum_a = sum_a + S[i][j] + S[j][i];
			}
			else if (is_team_a[i] == false && is_team_a[i] == is_team_a[j] )
			{
				sum_b = sum_b + S[i][j] + S[j][i];
			}
		}
	}
	res = min(res, abs(sum_a - sum_b));
}

void dfs(int idx,int num)  //num: a팀에 속한 수. 
{ 
	if (num == N / 2)
	{
		calc(); 
		return;
	}
	if (idx==N)
	{
		return;
	}
	is_team_a[idx] = true;
	dfs(idx + 1,num+1);
	is_team_a[idx] = false;
	dfs(idx + 1,num);


}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		S.assign(N, vector<int>(N, 0));
		is_team_a.assign(N, 0);
		res = 1000000000;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> S[i][j];
			}
		}
		is_team_a[0] = true;
		dfs(1,1);

		cout << "#" << tc << " " << res << "\n";
	}

	return 0;

}