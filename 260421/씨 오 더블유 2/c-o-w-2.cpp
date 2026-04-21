#include <iostream>
#include<string>
using namespace std;

int N, res;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	string str;
	cin >> str;
	for (int i = 0; i < N-2; i++)
	{
		if (str[i] == 'C')
			for (int j = i + 1; j < N - 1; j++)
				if (str[j] == 'O')
					for (int k = j + 1; k < N; k++)
						if (str[k] == 'W')
							res++;
	}
	cout << res;
	return 0;
}