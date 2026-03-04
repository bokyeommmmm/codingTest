#include <iostream>
#include <vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

int N, res;

vector<pair<int, int>> atomXY; //좌표
vector<int>atom; //살았나죽었나
vector<int>dir; // 방향
vector<int>energy; //에너지 
int board[4001][4001];
vector<pair<int, int>> visited;
int leftAtom; //남은 원자 수
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void move()
{
	for (int i = 0; i < N; i++) //모든원자돌면서
	{
		if (atom[i] == 0) //소멸된건 넘어가고
			continue;
		atomXY[i].first = atomXY[i].first + dx[dir[i]];
		atomXY[i].second = atomXY[i].second + dy[dir[i]];
		if (atomXY[i].first < 0 || atomXY[i].first>4000 || atomXY[i].second < 0 || atomXY[i].second>4000)
		{
			//범위 벗어나면
			atom[i] = 0;
			leftAtom--;
			continue;
		}

		int x = atomXY[i].first;
		int y = atomXY[i].second;

		if (board[x][y] == -1) { // 빈 자리면 일단드가고
			board[x][y] = i;
			visited.push_back({ x, y });
		}
		else if (board[x][y] >= 0) { // 다른 원자 있으면 
			int prev = board[x][y];
			res += energy[prev] + energy[i];
			atom[prev] = 0; //소멸
			atom[i] = 0;
			leftAtom -= 2;
			board[x][y] = -2; // 폭발 지역 표시
		}
		else if (board[x][y] == -2) { // 이미 폭발하는자리. 
			res += energy[i];
			atom[i] = 0;
			leftAtom -= 1;
		}
	}


	for (int i = 0; i < visited.size(); i++)
	{
		board[visited[i].first][visited[i].second] = -1;
	}
	visited.clear();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 0; i < 4001; i++) {
		for (int j = 0; j < 4001; j++) board[i][j] = -1;
	}
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;         //init 
		res = 0;
		atomXY.clear();
		dir.clear();
		energy.clear();
		atom.assign(N, 1); //1이면 살아있는녀석. 
		leftAtom = N;
		for (int i = 0; i < N; i++)
		{
			int x, y, d, e;
			cin >> x >> y >> d >> e;
			atomXY.push_back({ (x+1000) * 2,(y+1000) * 2 }); //두배 넓게 배치 -> 0.5초 충돌 해결. 
			dir.push_back(d);
			energy.push_back(e);
		}
		for (int i = 0; i < 4010; i++)
		{
			if (leftAtom <= 1)
				break;
			move();
		}
		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}