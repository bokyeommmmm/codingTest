#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

vector<vector<char>> board;
vector<pair<int, int>> arr;
vector<vector<int>>visited;
queue<pair<int, int>>q;
int chain;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

void down()
{
	for (int j = 0; j < 6; j++)
	{
		stack<char>s;
		for (int i = 0; i < 12; i++)
		{
			if (board[i][j] != '.')
			{
				s.push(board[i][j]);
				board[i][j] = '.';
			}
		}
		int bottom = 11;
		while (!s.empty())
		{
			board[bottom][j] = s.top();
			s.pop();
			bottom--;
		}
	}
}

void bomb()
{
	chain++;

	for (int i = 0; i < (int)arr.size(); i++)
	{
		int r = arr[i].first;
		int c = arr[i].second;
		board[r][c] = '.';
	}
}

void bfs()
{
	vector<pair<int, int>> temp;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		char cur = board[r][c];
		temp.push_back({ r,c });
		for (int i = 0; i < 4; i++)
		{
			int nr = r + dr[i];
			int nc = c + dc[i];
			if (nr < 0 || nc < 0 || nr >= 12 || nc >= 6)
				continue;
			if (visited[nr][nc] == 1)
				continue;
			if (board[nr][nc] != cur)
				continue;
			visited[nr][nc] = 1;
			q.push({ nr,nc });
		}
	}

	if (temp.size() > 3)
	{
		for (int i = 0; i < temp.size(); i++)
		{
			arr.push_back({ temp[i].first,temp[i].second });
		}
	}
}

void simul()
{

	// 계속 반복하는데 안터지면 그만 돌도록 해야할듯. 
	while (true)
	{
		arr.clear();
		visited.assign(12, vector<int>(6, 0));

		for (int i = 0; i < 12; i++)  //4개 이상 붙어있는녀석 좌표 확인. 
		{
			for (int j = 0; j < 6; j++)
			{
				if (board[i][j] != '.'&&visited[i][j]==0)
				{
					visited[i][j] = 1;
					q.push({ i,j });
					bfs();
				}
			}
		}
		if (arr.size() == 0)
			break;
		bomb();
		down();
	}
}

void init()
{
	board.assign(12, vector<char>(6));
	visited.assign(12, vector<int>(6));

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cin >> board[i][j];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	init();
	
	simul();
	cout << chain;
	return 0;
}