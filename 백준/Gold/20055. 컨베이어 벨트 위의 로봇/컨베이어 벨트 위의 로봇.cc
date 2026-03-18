#include<iostream>
#include<vector>
using namespace std;

int N, K, zeros, res;
vector<int>A;
vector<int>robot;

void simul()
{
	while (zeros<K)
	{
		res++;
		int temp;
		temp = A[N * 2 - 1];

		for (int i = N * 2 - 1; i > 0; i--)
		{
			A[i] = A[i - 1];
		}

		A[0] = temp;
		temp = robot[N - 1];
		for (int i = N - 1; i > 0; i--)
		{
			robot[i] = robot[i - 1];
		}
		robot[0] = 0;
		robot[N - 1] = 0;

		//-----------------------------------------------------------------------------------


		for (int i = N  - 1; i > 0; i--)
		{
			if (robot[i] == 0 && A[i] > 0 && robot[i - 1] == 1)
			{
				A[i]--;
				robot[i - 1] = 0;
				robot[i] = 1;
				if (A[i] == 0)
					zeros++;
			}
		}
		//-----------------------------------------------------------------------------------


		if (A[0] != 0)
		{
			robot[0] = 1;
			A[0]--;
			if (A[0] == 0)
				zeros++;
		}
		//-----------------------------------------------------------------------------------
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> K;
	A.assign(N * 2, 0);
	robot.assign(N, 0);
	for (int i = 0; i < N * 2; i++)
	{
		int temp;
		cin >> temp;
		A[i] = temp;
		if (temp == 0)
		{
			zeros++;
		}
	}
	if (zeros < K)
		simul();

	cout << res;
	return 0;
}