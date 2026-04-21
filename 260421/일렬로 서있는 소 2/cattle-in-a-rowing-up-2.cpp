#include <iostream>
#include <vector>

using namespace std;

int N, res;
vector<int>A;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		A.push_back(temp);
	}
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; i < N - 1; i++)
		{
			for (int k = j + 2; k < N; k++)
			{
				if (A[i] <= A[j] && A[j] <= A[k])
					res++;
			}
		}
	}

	cout << res;
	return 0;
}