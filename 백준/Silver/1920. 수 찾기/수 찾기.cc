#include<iostream>
#include<set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N;
	set<int>s;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		s.insert(temp);
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		if (s.count(temp) != 0) //있으면
		{
			cout << 1 << "\n";
		}
		else
			cout << 0 << "\n";

	}

	return 0;
}