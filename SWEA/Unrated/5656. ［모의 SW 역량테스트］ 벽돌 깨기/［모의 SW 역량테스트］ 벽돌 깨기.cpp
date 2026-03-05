#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

int N, W, H; //벽돌개수, 너비, 높이 
int res;
vector<vector<int>>board;
queue<pair<int, int>>q;
vector<int>arr; //순열 
int calc()
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
	return sum;
}
void down() //붕뜬놈들 내리기. 
{
	for (int j = 0; j < W; j++)
	{
		stack<int>s;
		for (int i = 0; i < H; i++)
		{
			if (board[i][j] != 0)
			{
				s.push(board[i][j]);
				board[i][j] = 0;
			}
		}
		int r = H - 1;
		while (!s.empty())
		{
			board[r][j] = s.top();
			s.pop();
			r--;
		}

	}
}

void bomb(int sr, int sc, int power)
{
	for (int j = -power + 1; j < power; j++) // 가로 펑
	{
		if (sc + j < 0 || sc + j >= W)  //범위밖은 안건든다. 
			continue;
		if (board[sr][sc + j] == 0)
			continue;
		if (board[sr][sc + j] == 1)  //범위 내 1 벽돌있으면 깨자. 
		{
			board[sr][sc + j] = 0;
		}
		if (board[sr][sc + j] > 1) //강한놈이면 
		{
			int p = board[sr][sc + j];
			board[sr][sc + j] = 0;
			bomb(sr, sc + j, p);

		}
	}
	for (int i = -power + 1; i < power; i++) // 세로 펑 
	{
		if (sr + i < 0 || sr + i >= H) 
			continue;
		if (board[sr + i][sc] == 0)
			continue;
		if (board[sr + i][sc] == 1)  
		{
			board[sr + i][sc] = 0;
		}
		if (board[sr + i][sc] > 1)
		{
			int p = board[sr + i][sc];
			board[sr + i][sc] = 0;
			bomb(sr + i, sc, p);

		}
	}

}
void findTarget()
{
	vector<vector<int>> temp = board; //기존거 복사해두고.
	for (int i = 0; i < N; i++)
	{
		int r = H;
		int c = arr[i];
		int power = 0;
		for (int k = 0; k < H; k++)
		{
			if (board[k][c] != 0) //처음 벽돌을 만나면
			{
				power = board[k][c];
				r = k;
				break;
			}
		}
		if (r == H) //깰것없으면 x 
			continue;

		bomb(r, c, power); //연쇄 ㄱㄱ
		down(); //밑으로내리고 
	}
	res = min(res,calc()); //최종계산 
	board = temp; //원복까지. 
}

void dfs1(int cnt)
{
	if (res == 0) return;
	if (cnt == N)
	{
		findTarget();
		return;
	}
	for (int i = 0; i < W; i++)
	{
		arr.push_back(i);
		dfs1(cnt + 1);
		arr.pop_back();
	}
}
void init()
{
	cin >> N >> W >> H;
	res = W * H;
	board.assign(H, vector<int>(W, 0));
	arr.clear();
	while (!q.empty())
	{
		q.pop();
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cin >> board[i][j];
		}
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
		init();
		dfs1(0);


		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}