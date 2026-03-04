#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//지도사이즈, 주사위초기좌표, 명령 수
int N, M, x, y, K;
int dx[5] = { 0,0,0,-1,1 }; //X,동,서,북,남  
int dy[5] = { 0,1,-1,0,0 };

vector<vector<int>> map;

int dice[6];

void move(int dir)
{
	int nx = x + dx[dir];
	int ny = y + dy[dir];

	if (nx < 0 || ny < 0 || nx >= N || ny >= M)
		return;

	x = nx;
	y = ny;

	int temp[6];

	if (dir == 1) // 동
	{
		temp[0] = dice[4];
		temp[1] = dice[0];
		temp[2] = dice[2];
		temp[3] = dice[3];
		temp[4] = dice[5];
		temp[5] = dice[1];
	}
	else if (dir == 2) // 서
	{
		temp[0] = dice[1];
		temp[1] = dice[5];
		temp[2] = dice[2];
		temp[3] = dice[3];
		temp[4] = dice[0];
		temp[5] = dice[4];
	}
	else if (dir == 3) // 북
	{
		temp[0] = dice[3];
		temp[1] = dice[1];
		temp[2] = dice[0];
		temp[3] = dice[5];
		temp[4] = dice[4];
		temp[5] = dice[2];
	}
	else if (dir == 4) // 남
	{
		temp[0] = dice[2];
		temp[1] = dice[1];
		temp[2] = dice[5];
		temp[3] = dice[0];
		temp[4] = dice[4];
		temp[5] = dice[3];
	}

	for (int i = 0; i < 6; i++)
	{
		dice[i] = temp[i];
	}

	if (map[x][y] == 0)
	{
		map[x][y] = dice[5];
	}
	else
	{
		dice[5] = map[x][y];
		map[x][y] = 0;
	}

	cout << dice[0] << "\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M >> x >> y >> K;

	map.assign(N, vector<int>(M, 0));

	for (int i = 0; i < 6; i++)
		dice[i] = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++)
	{
		int temp;
		cin >> temp;
		move(temp);
	}

	return 0;
}