#include <iostream>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int res = 0;

	string str;
	cin >> str;

	for (int i = 0; i < str.size() - 3; i++)
		if (str[i] == '('&&str[i + 1] == '(')
			for (int j = i + 2; j < str.size() - 1; j++)
				if (str[j] == ')'&&str[j + 1] == ')')
					res++;
	cout << res;
	return 0;
}