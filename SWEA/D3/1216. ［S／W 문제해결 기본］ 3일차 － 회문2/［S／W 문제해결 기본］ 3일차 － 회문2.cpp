#include<iostream>
#include<vector>
#include<string>
using namespace std;

int res;
bool isDone;
vector<vector<char>> board1;
vector<vector<char>> board2;

void search(int len)
{
	for (int col = 0; col < 100; col++)
	{
		string str;
		for (int i = 0; i < 100; i++)
		{
			str += board1[col][i];
		}

		for (int i = 0; i < 100 - len + 1; i++)
		{
			int l = i;
			int r = i + len - 1;
			bool ok = true;

			while (l < r)
			{
				if (str[l] != str[r])
				{
					ok = false;
					break;
				}
				l++;
				r--;
			}

			if (ok)
			{
				isDone = true;
				res = len;
				return;
			}
		}
	}

	for (int col = 0; col < 100; col++)
	{
		string str;
		for (int i = 0; i < 100; i++)
		{
			str += board2[col][i];
		}

		for (int i = 0; i < 100 - len + 1; i++)
		{
			int l = i;
			int r = i + len - 1;
			bool ok = true;

			while (l < r)
			{
				if (str[l] != str[r])
				{
					ok = false;
					break;
				}
				l++;
				r--;
			}

			if (ok)
			{
				isDone = true;
				res = len;
				return;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	for (int tc = 1; tc <= 10; tc++)
	{
		int k;
		cin >> k;
		res = 0;
		isDone = false;
		board1.assign(100, vector<char>(100, '\0'));
		board2.assign(100, vector<char>(100, '\0'));

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				char a;
				cin >> a;
				board1[i][j] = a;
				board2[j][i] = a;
			}
		}

		for (int i = 100; i > 0; i--)
		{
			if (isDone == false)
				search(i);
			else
				break;
		}

		cout << "#" << k << " " << res << "\n";
	}

	return 0;
}