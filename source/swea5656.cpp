#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int N, W, H; //벽돌개수. 
int power, res;
vector<vector<int>>board;
queue<pair<int, int>>q;
void calc()
{
	int sum = 0;
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] != 0)
				sum++;
		}
	}
	res = min(res, sum);
}
void down() //붕뜬놈들 내리기. 
{
	for (int j = 0; j < W; j++)
	{
		stack<int>temp;
		for (int i = 0; i < H; i++)
		{
			if (board[i][j] != 0)
			{
				temp.push(board[i][j]);
				board[i][j] = 0;
			}
		}
		for (int i = H - 1; i > H - 1 - temp.size(); i++)
		{
			board[i][j] = temp.top();
			temp.pop();
		}
	}
}
void bomb(int sr, int sc, int power)
{
	q.push({ sr,sc });
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		for (int i = -power + 1; i < power; i++)
		{
			for (int j = -power + 1; j < power; j++)
			{
				if (r + i < 0 || c + j < 0 || r + i >= H || c + j >= W)
					continue;
				if (board[r + i][c + j] > 1)
				{
					q.push({ r + i,c + j });
				}
				else if (board[r + i][c + j] == 1)
					board[r + i][c + j] = 0;
			}
		}
	}
	down();
}

void dfs(int idx, int cnt)
{
	if (cnt == N)
	{
		calc();
		return;
	}
	if (idx == W)
	{
		return;
	}

	for (int j = 0; j < W; j++)
	{
		int i = 0;
		for (i; i < H; i++)
		{
			if (board[i][j] != 0) {
				power = board[i][j];
				break;
			}
		}
		if (i == H) //해당 칸 전부 0이면
			continue;
		auto temp = board;
		bomb(i, idx + j, power);
		dfs(idx + j, cnt + 1);
		board = temp;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> W >> H;
		res = W * H;
		board.assign(H, vector<int>(N, 0));
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> board[i][j];
			}
		}
		dfs(0, 0);
		cout << "#" << tc << " " << "" << "\n";
	}
	return 0;
}