#include <iostream>
#include<vector>
using namespace std;

int N, blue, white;
vector<vector<int>>arr;

void func(int sr, int sc, int r, int c, int n)
{
	if (n == 1) {
		if (arr[sr][sc] == 1)
		{
			blue++;
			return;
		}
		else
		{
			white++;
			return;
		}

	}
	int sum = 0;

	for (int i = sr; i < r; i++)
		for (int j = sc; j < c; j++)
			sum += arr[i][j];
	if (sum == n * n)
	{
		blue++;
		return;
	}
	else if (sum == 0)
	{
		white++;
		return;
	}
	else
	{
		int nr = (sr + r) / 2;
		int nc = (sc + c) / 2;

		func(sr, sc, nr, nc, n / 2);
		func(sr, nc, nr, c, n / 2);
		func(nr, sc, r, nc, n / 2);
		func(nr, nc, r, c, n / 2);
	}

}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	arr.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
		}
	}
	func(0, 0, N, N, N);

	cout << white << "\n" << blue;
	return 0;
}