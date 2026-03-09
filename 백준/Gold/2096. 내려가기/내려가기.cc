#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;

int dpm[2][3] = {};
int dpM[2][3] = {};
int arr[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;

	for (int j = 0; j < 3; j++)
	{
		cin >> dpm[0][j];
		dpM[0][j] = dpm[0][j];
	}

	for (int i = 1; i < N; i++)
	{
		cin >> arr[0] >> arr[1] >> arr[2];

		dpm[1][0] = arr[0] + min(dpm[0][0], dpm[0][1]);
		dpm[1][1] = arr[1] + min(dpm[0][0], min(dpm[0][1], dpm[0][2]));
		dpm[1][2] = arr[2] + min(dpm[0][1], dpm[0][2]);

		dpM[1][0] = arr[0] + max(dpM[0][0], dpM[0][1]);
		dpM[1][1] = arr[1] + max(dpM[0][0], max(dpM[0][1], dpM[0][2]));
		dpM[1][2] = arr[2] + max(dpM[0][1], dpM[0][2]);

		for (int j = 0; j < 3; j++)
		{
			dpm[0][j] = dpm[1][j];
			dpM[0][j] = dpM[1][j];
		}
	}

	cout << max(dpM[0][0], max(dpM[0][1], dpM[0][2])) << " "
		<< min(dpm[0][0], min(dpm[0][1], dpm[0][2]));

	return 0;
}