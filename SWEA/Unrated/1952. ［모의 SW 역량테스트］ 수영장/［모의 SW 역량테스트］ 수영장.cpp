#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int T;
vector<int>prices;
vector<int>plans;
int res;
void init()
{
	prices.clear();
	plans.clear();
	for (int i = 0; i < 4; i++)
	{
		int temp;
		cin >> temp;
		prices.push_back(temp);
	}
	for (int i = 0; i < 12; i++)
	{
		int temp;
		cin >> temp;
		plans.push_back(temp);
	}
	res = prices[3]; //일단 1년권이 젤 싼걸로 
}

void dfs(int month, int cost)
{
	if (month > 11)
	{
		res = min(res, cost);
		return;
	}
	dfs(month + 1, cost + min(plans[month] * prices[0],prices[1]));
	dfs(month + 3, cost + prices[2]);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		init();
		dfs(0, 0);

		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}