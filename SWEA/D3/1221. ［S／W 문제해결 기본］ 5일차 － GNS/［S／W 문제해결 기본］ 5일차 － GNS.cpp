#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int N;
int res[10];
map<int, string>m;
void print()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < res[i]; j++)
		{
			cout << m[i] << " ";
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	m.insert({ 0,"ZRO" });
	m.insert({ 1,"ONE" });
	m.insert({ 2,"TWO" });
	m.insert({ 3,"THR" });
	m.insert({ 4,"FOR" });
	m.insert({ 5,"FIV" });
	m.insert({ 6,"SIX" });
	m.insert({ 7,"SVN" });
	m.insert({ 8,"EGT" });
	m.insert({ 9,"NIN" });
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		string tcNum;
		cin >> tcNum;
		cin >> N;
		for (int i = 0; i < 10; i++)
		{
			res[i] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			string temp;
			cin >> temp;
			

			if (temp == "ZRO")res[0]++;
			else if (temp == "ONE")res[1]++;
			else if (temp == "TWO")res[2]++;
			else if (temp == "THR")res[3]++;
			else if (temp == "FOR")res[4]++;
			else if (temp == "FIV")res[5]++;
			else if (temp == "SIX")res[6]++;
			else if (temp == "SVN")res[7]++;
			else if (temp == "EGT")res[8]++;
			else if (temp == "NIN")res[9]++;
		}

		cout << tcNum << "\n"; 
		print();
		cout << "\n";
	}

	return 0;
}