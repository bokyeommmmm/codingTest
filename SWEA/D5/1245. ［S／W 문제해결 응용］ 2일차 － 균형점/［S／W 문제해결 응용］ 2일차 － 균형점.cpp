#include <iostream>
#include <algorithm>
#include<iomanip>
using namespace std;

int T, N;
double magX[10], magM[10], res[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> magX[i];
		for (int i = 0; i < N; i++)
			cin >> magM[i];

		for (int i = 0; i < N - 1; i++)
		{
			double l = magX[i], r = magX[i + 1], mid;
			for (int it = 0; it < 100; it++)
			{
				double leftF = 0, rightF = 0;
				mid = (l + r) / 2;

				for (int j = 0; j < N; j++)
				{
					double d = (magX[j] - mid);
					if (d < 0) //왼쪽것들
						leftF += magM[j] / (d * d);
					else
						rightF += magM[j] / (d * d);
				}

				if (leftF > rightF) //왼쪽이 더 세게당기면 오른쪽으로 가보자 
					l = mid;
				else //오른쪽이 더 세게당기면 왼쪽으로 
					r = mid;

			}
			res[i] = mid;
		}


		//print
		cout << "#" << tc << " ";
		for (int i = 0; i < N-1; i++)
		{
			cout << fixed << setprecision(10) << res[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}