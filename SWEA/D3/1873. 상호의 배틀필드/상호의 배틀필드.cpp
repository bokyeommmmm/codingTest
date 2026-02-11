#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<char>> map;

int H, W, N;
string com;
int x, y;
void simul(int idx)
{
	if (com[idx] == 'U')
	{
		if (x - 1 >= 0 && map[x - 1][y] == '.')
		{
			map[x][y] = '.';
			map[x - 1][y] = '^';
			x--;
		}

		else
			map[x][y] = '^';
	}
	if (com[idx] == 'D')
	{
		if (x + 1 < H && map[x + 1][y] == '.')
		{
			map[x][y] = '.';
			map[x + 1][y] = 'v';
			x++;
		}

		else
			map[x][y] = 'v';
	}
	if (com[idx] == 'L')
	{
		if (y - 1 >= 0 && map[x][y - 1] == '.')
		{
			map[x][y] = '.';
			map[x][y - 1] = '<';
			y--;
		}

		else
			map[x][y] = '<';
	}
	if (com[idx] == 'R')
	{
		if (y + 1 < W && map[x][y + 1] == '.')
		{
			map[x][y] = '.';
			map[x][y + 1] = '>';
			y++;
		}

		else
			map[x][y] = '>';
	}
	if (com[idx] == 'S')
	{
		int xx = x;
		int yy = y;
		if (map[x][y] == '^')
		{
			while (true)
			{
				xx--;
				if (xx < 0 || map[xx][y] == '#')
					break;
				else if (map[xx][y] == '*')
				{
					map[xx][y] = '.';
					break;
				}
			}
		}
		else if (map[x][y] == 'v')
		{
			while (true)
			{
				xx++;
				if (xx >= H || map[xx][y] == '#')
					break;
				else if (map[xx][y] == '*')
				{
					map[xx][y] = '.';
					break;
				}
			}
		}
		else if (map[x][y] == '<')
		{
			while (true)
			{
				yy--;
				if (yy < 0 || map[x][yy] == '#')
					break;
				else if (map[x][yy] == '*')
				{
					map[x][yy] = '.';
					break;
				}
			}
		}
		else if (map[x][y] == '>')
		{
			while (true)
			{
				yy++;
				if (yy >= W || map[x][yy] == '#')
					break;
				else if (map[x][yy] == '*')
				{
					map[x][yy] = '.';
					break;
				}
			}
		}
	}
}

void print()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
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
		cin >> H >> W;
		map.assign(H, vector<char>(W, ' '));
		for (int i = 0; i < H; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < W; j++)
			{
				if (str[j] == '^' || str[j] == 'v' || str[j] == '<' || str[j] == '>')
				{
					x = i;
					y = j;
				}

				map[i][j] = str[j];
			}
		}
		cin >> N;
		cin >> com;
		for (int i = 0; i < N; i++)
		{
			simul(i);

		}

		cout << "#" << tc << " "; print(); 
	}

	return 0;
}