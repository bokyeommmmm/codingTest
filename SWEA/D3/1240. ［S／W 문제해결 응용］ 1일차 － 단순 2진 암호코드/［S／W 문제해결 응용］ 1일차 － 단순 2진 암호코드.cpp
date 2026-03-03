#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int N, M;
vector<string>arr;
int r2, c2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N >> M;
		arr.clear();
		r2 = 0;
		c2 = 0;
		for (int i = 0; i < N; i++)
		{
			string str;
			cin >> str;
			arr.push_back(str);
		}

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] == '1') //마지막에 나온 1 기준으로 박스 잡자.
				{
					r2 = i;
					c2 = j;
				}
			}
		}

		bool isOdd = true;
		int check = 0;
		int sum = 0;
		for (int c = c2 - 55; c <= c2; c = c + 7)
		{

			string temp = "";

			for (int j = c; j < c+7; j++)
			{
				temp += arr[r2][j];
			}
			if (temp == "0001101")
			{
				if (isOdd)
				{
					check += 0 * 3;
					isOdd = false;

				}
				else
				{
					check += 0;
					isOdd = true;
				}
				sum += 0;
			}
			else if (temp == "0011001")
			{
				if (isOdd)
				{
					check += 1 * 3;
					isOdd = false;

				}
				else
				{
					check += 1;
					isOdd = true;
				}
				sum += 1;
			}
			else if (temp == "0010011")
			{
				if (isOdd)
				{
					check += 2 * 3;
					isOdd = false;

				}
				else
				{
					check += 2;
					isOdd = true;
				}
				sum += 2;
			}
			else if (temp == "0111101")
			{
				if (isOdd)
				{
					check += 3 * 3;
					isOdd = false;

				}
				else
				{
					check += 3;
					isOdd = true;
				}
				sum += 3;
			}
			else if (temp == "0100011")
			{
				if (isOdd)
				{
					check += 4 * 3;
					isOdd = false;

				}
				else
				{
					check += 4;
					isOdd = true;
				}
				sum += 4;
			}
			else if (temp == "0110001")
			{
				if (isOdd)
				{
					check += 5 * 3;
					isOdd = false;

				}
				else
				{
					check += 5;
					isOdd = true;
				}
				sum += 5;
			}
			else if (temp == "0101111")
			{
				if (isOdd)
				{
					check += 6 * 3;
					isOdd = false;

				}
				else
				{
					check += 6;
					isOdd = true;
				}sum += 6;
			}
			else if (temp == "0111011")
			{
				if (isOdd)
				{
					check += 7 * 3;
					isOdd = false;

				}
				else
				{
					check += 7;
					isOdd = true;
				}
				sum += 7;
			}
			else if (temp == "0110111")
			{
				if (isOdd)
				{
					check += 8 * 3;
					isOdd = false;

				}
				else
				{
					check += 8;
					isOdd = true;
				}
				sum += 8;
			}
			else if (temp == "0001011")
			{
				if (isOdd)
				{
					check += 9 * 3;
					isOdd = false;

				}
				else
				{
					check += 9;
					isOdd = true;
				}
				sum += 9;
			}


		}
		if (check % 10 == 0)
			cout << "#" << tc << " " << sum << "\n";
		else
			cout << "#" << tc << " " << 0 << "\n";
	}



	return 0;
}