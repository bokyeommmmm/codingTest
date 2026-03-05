#include <iostream>
#include <vector>
#include<sstream>
#include<map>
using namespace std;

int N, M;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	map<string, string> m;
	for (int i = 0; i < N; i++)
	{
		//string str;
		//cin >> str;
		//stringstream s1(str);
		string a, b;
		cin >> a >> b;
		m.insert({ a,b });
	}
	for (int i = 0; i < M; i++)
	{
		string str;
		cin >> str;
		cout << m[str] << "\n";
	}

	return 0;
}