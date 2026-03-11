#include <iostream>
#include <vector>
#include<string>
#include<set>
using namespace std;

int K, len;

string str;
set<string>s;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> K;
		cin >> str;
		s.clear();
		len = str.size();

		for (int i = 0; i < len; i++)          // 출발위치
		{
			for (int j = 1; i + j <= len; j++) // 문자열 길이
			{
				s.insert(str.substr(i, j));
			}
		}
		int cnt = 0;
		bool ok = false;
		for (auto it : s)
		{
			if(cnt==K-1)
			{ 
				cout << "#" << tc << " " << it << "\n";
				ok = true;
				break;
			}
			cnt++;

		}
		if(ok==false)
			cout << "#" << tc << " " << "none" << "\n";

	}

	return 0;
}