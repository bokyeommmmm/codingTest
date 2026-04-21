#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, totalNum, res;
vector<int>room;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	res = 2000000000;
	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		totalNum += temp;
		room.push_back(temp);
	}
	for (int i = 0; i < N; i++)
	{
		room.push_back(room[i]);
		int sum = 0;
		for (int j = 1; j < N; j++)
		{
			sum = sum + ( j * room[i + j] );//거리 x 사람 수
		}
		res = min(res, sum);
	}
	cout << res;
	return 0;
}