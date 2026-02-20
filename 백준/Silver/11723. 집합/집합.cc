#include <iostream>
#include <set>
#include<string>
using namespace std;
set<int>s;
set<int>all;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int M;
	cin >> M;
	for (int i = 1; i <= 20; i++)
	{
		all.insert(i);
	}
	for (int i = 0; i < M; i++)
	{
		string str;
		int num;
		cin >> str;
		if (str!="all"&&str!="empty")
		{
			cin >> num;
		}

		if (str == "add")
		{
			s.insert(num);
		}
		else if (str == "remove")
		{
			s.erase(num);
		}
		else if (str == "check")
		{
			if (s.count(num) != 0)
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}
		else if (str == "toggle")
		{
			if (s.count(num) > 0)
				s.erase(num);
			else
				s.insert(num);
		}
		else if (str == "all")
		{
			s = all;
		}
		else if (str == "empty")
		{
			s.clear();
		}
	}

	return 0;
}