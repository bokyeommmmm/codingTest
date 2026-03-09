#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		int N;
		cin >> N;

		vector<long long> x(N);
		vector<long long> y(N);

		for (int i = 0; i < N; i++)
		{
			cin >> x[i];
		}

		for (int i = 0; i < N; i++)
		{
			cin >> y[i];
		}

		double E;
		cin >> E;

		vector<long long>minDist(N, 4e18);
		vector<int>visited(N, 0);
		minDist[0] = 0;
		long long total = 0;

		for (int i = 0; i < N; i++)
		{
			int u = -1;

			long long Min = (long long)4e18;

			for (int j = 0; j < N; j++)
			{
				if (visited[j] == 1)
					continue;

				if (minDist[j] < Min)
				{
					Min = minDist[j];
					u = j;
				}
			}

			visited[u] = 1;

			total += minDist[u];
			for (int v = 0; v < N; v++)
			{
				if (visited[v] == 1)
					continue;

				long long dx = x[u] - x[v];

				long long dy = y[u] - y[v];

				long long dist = dx * dx + dy * dy;

				if (dist < minDist[v])
				{
					minDist[v] = dist;
				}
			}
		}

				long long answer = (long long)round(total * E);
		
				cout << "#" << tc << " " << answer << "\n";
	}

	return 0;
}