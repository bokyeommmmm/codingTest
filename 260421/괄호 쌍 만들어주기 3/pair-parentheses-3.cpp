#include <iostream>
#include <vector>
#include<string>

using namespace std;

int res;

int main() {
	// Please write your code here.
	string str;
	getline(cin, str);
	
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
		{
			for (int j = i+1; j < str.size(); j++)
			{
				if (str[j] == ')')
					res++;
			}
		}
	}

	cout << res;
	return 0;
}