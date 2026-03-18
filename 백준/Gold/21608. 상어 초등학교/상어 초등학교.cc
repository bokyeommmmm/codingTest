#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
vector<vector<int>>friends;
vector<vector<int>>classroom;
vector<int>arr;

int calc()
{
	int res = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <=N; j++)
		{
			int cnt = 0;
			int me = classroom[i][j];
			for (int d = 0; d < 4; d++)
			{
				int nr = i + dr[d];
				int nc = j + dc[d];
				if (nr<1 || nc<1 || nr>N || nc>N)
					continue;
				for (int k = 0; k < 4; k++)
				{
					if (friends[me][k] == classroom[nr][nc])
						cnt++;
				}
			}
			if (cnt == 1)
				res += 1;
			else if (cnt == 2)
				res += 10;
			else if (cnt == 3)
				res += 100;
			else if (cnt == 4)
				res += 1000;
		}
	}
	return res;
}
void  simul(int me)
{
	vector<vector<int>>score(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>>score2(N + 1, vector<int>(N + 1, 0));

	int maxcnt = 0;
	int maxcnt2 = 0;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (classroom[i][j] != 0)
				continue;
			int cnt = 0; //좋아하는 사람 수
			int cnt2 = 0;// 빈자리 수
			for (int d = 0; d < 4; d++)
			{
				int nr = i + dr[d];
				int nc = j + dc[d];
				if (nr<1 || nc<1 || nr>N || nc>N)
					continue;
				for (int k = 0; k < 4; k++)
				{
					if (friends[me][k] == classroom[nr][nc])
						cnt++;
				}
				if (classroom[nr][nc] == 0)
					cnt2++;
			}
			score[i][j] = cnt;
			maxcnt = max(cnt, maxcnt);
			score2[i][j] = cnt2;
			maxcnt2 = max(cnt2, maxcnt2);
		}
	}
	for (int i = maxcnt; i >= 0; i--)
	{
		for (int j = maxcnt2; j >= 0; j--)
		{
			for (int r = 1; r <= N; r++)
			{
				for (int c = 1; c <=N; c++)
				{
					if (classroom[r][c] == 0&&score[r][c] == i && score2[r][c] == j)
					{
						classroom[r][c] = me;
						return;
					}
				}
			}
		}
	}

	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	friends.assign(N*N + 1, vector<int>(0));
	classroom.assign(N + 1, vector<int>(N + 1, 0));
	for (int i = 1; i <= N * N; i++)
	{
		int me;
		cin >> me;
		arr.push_back(me);
		for (int j = 0; j < 4; j++)
		{
			int temp;
			cin >> temp;
			friends[me].push_back(temp);
		}

	}
	classroom[2][2] = arr[0];
	for (int i = 1; i < N*N; i++)
	{

		simul(arr[i]);
	}
	cout << calc();

	return 0;
}