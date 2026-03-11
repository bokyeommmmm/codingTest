#include <iostream>
#include <vector>
using namespace std;

int R, C, T, res;
vector<vector<int>> A;
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
vector<int>airFilter;


void calc()
{
	
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			res += A[r][c];
		}
	}
	res = res + 2;
}
void flow()
{
	int r1, c1, r2, c2;
	r1 = airFilter[0];
	r2 = airFilter[1];
	//위쪽 반시계 
	for (int r = r1-1; r > 0; r--)
	{
		A[r][0] = A[r - 1][0];
	}
	for (int c = 0; c < C - 1; c++)
	{
		A[0][c] = A[0][c + 1];
	}
	for (int r = 0; r < r1; r++)
	{
		A[r][C - 1] = A[r + 1][C - 1];
	}
	for (int c = C - 1; c > 1; c--)
	{
		A[r1][c] = A[r1][c - 1];
	}
	A[r1][1] = 0;

	//아래쪽 시계
	for (int r = r2+1; r < R - 1; r++)
	{
		A[r][0] = A[r + 1][0];
	}
	for (int c = 0; c < C - 1; c++)
	{
		A[R - 1][c] = A[R - 1][c + 1];
	}
	for (int r = R - 1; r > r2; r--)
	{
		A[r][C - 1] = A[r - 1][C - 1];
	}
	for (int c = C - 1; c > 1; c--)
	{
		A[r2][c] = A[r2][c - 1];
	}
	A[r2][1] = 0;
}

void spread()
{
	vector<vector<int>> B(R, vector<int>(C, 0));
	for (int r = 0; r < R; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (A[r][c] > 0)	 //미세먼지면 
			{
				int cnt = 0; //주위에 퍼질 수 있는 칸 수 .
				int fineDust = A[r][c] / 5;
				for (int i = 0; i < 4; i++)
				{
					int nr = r + dr[i];
					int nc = c + dc[i];
					if (nr < 0 || nc < 0 || nr >= R || nc >= C)
						continue;
					if (A[nr][nc] == -1)
						continue;
					cnt++;
					B[nr][nc] += fineDust;
				}
				B[r][c] += A[r][c] - fineDust * cnt;
			}
		}
	}

	A = B;
	A[airFilter[0]][0] = -1;
	A[airFilter[1]][0] = -1;
}

void simul()
{
	int t = 0;
	while (true)
	{
		spread();
		flow();
		t++;
		if (t == T)
			break;
	}
	calc();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	A.assign(R, vector<int>(C, 0));

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int temp;
			cin >> temp;
			A[i][j] = temp;
			if (temp == -1)
			{
				airFilter.push_back(i);
			}
		}
	}
	simul();
	cout << res;
	return 0;
}