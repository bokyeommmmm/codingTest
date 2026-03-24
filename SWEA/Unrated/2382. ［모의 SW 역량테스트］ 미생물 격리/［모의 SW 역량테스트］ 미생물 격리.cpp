#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int N, M, K; // 셀의 개수 N, 격리 시간 M, 미생물 군집의 개수 K
vector<vector<int>> board;
int dr[5] = { 0,-1,1,0,0 };
int dc[5] = { 0,0,0,-1,1 };

struct unit
{
	int r, c, num, dir;
	bool alive;
};
vector<unit>units;

void init()
{
	cin >> N >> M >> K;
	units.clear();
	board.assign(N, vector<int>(N, -1));
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			board[i][j] = 0;
		}
	}
	for (int i = 0; i < K; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		units.push_back({ a,b,c,d,true });
	}
}
void move(int idx)
{
	units[idx].r = units[idx].r + dr[units[idx].dir];
	units[idx].c = units[idx].c + dc[units[idx].dir]; //이동하고
	if (units[idx].r == 0 || units[idx].r == N - 1 || units[idx].c == 0 || units[idx].c == N - 1) //약품셀이면
	{
		units[idx].num /= 2;
		if (units[idx].num == 0)
		{
			units[idx].alive = false;
			return;
		}
		if (units[idx].dir == 1)
			units[idx].dir = 2;
		else if (units[idx].dir == 2)
			units[idx].dir = 1;
		else if (units[idx].dir == 3)
			units[idx].dir = 4;
		else if (units[idx].dir == 4)
			units[idx].dir = 3;
	}
	else  //
	{
		board[units[idx].r][units[idx].c]++;
	}
}
void join(int r, int c)
{
	int biggest = 0;
	int dir = 0;
	int sum = 0;
	vector<int>idxx;
	for (int i = 0; i < units.size(); i++)
	{
		if (r == units[i].r&&c == units[i].c&&units[i].alive==true)
		{
			idxx.push_back(i);
			sum += units[i].num;
			if (biggest < units[i].num)
			{
				biggest = units[i].num;
				dir = units[i].dir;
			}
		}
	}
	units[idxx[0]].dir = dir;
	units[idxx[0]].num = sum;
	for (int i = 1; i < idxx.size(); i++)
	{
		units[idxx[i]].alive = false;
		units[idxx[i]].num = 0;
		units[idxx[i]].r = 0;
		units[idxx[i]].c = 0;
	}

}
void simul()
{
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			board[i][j] = 0;
		}
	}
	for (int i = 0; i < units.size(); i++)
	{
		if (units[i].alive == true)
			move(i);
	}
	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			if (board[i][j] > 1)
				join(i, j);
		}
	}
}
int calc()
{
	int sum = 0;
	for (int i = 0; i < units.size(); i++)
	{
		if (units[i].alive == true)
			sum += units[i].num;
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		init();
		for (int i = 0; i < M; i++)
		{
			simul();
		}
		cout << "#" << tc << " " << calc() << "\n";
	}

	return 0;
}