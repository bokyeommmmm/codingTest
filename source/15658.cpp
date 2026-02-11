#include <iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int N;
int maxres = -1000000000;
int minres = 1000000000;

vector<int> num;
stack<int>cur;
int sign[4]; //+ - * /

void func(int idx) {

	if (idx == N-1)
	{
		maxres = max(maxres, cur.top());
		minres = min(minres, cur.top());
		return;
	}

	if (sign[0] > 0)
	{
		cur.push(cur.top() + num[idx + 1]);
		sign[0]--;
		func(idx + 1);
		sign[0]++;
		cur.pop();
	}
	if (sign[1] > 0)
	{
		cur.push(cur.top() - num[idx + 1]);
		sign[1]--;
		func(idx + 1);
		sign[1]++;
		cur.pop();
	}
	if (sign[2] > 0)
	{
		cur.push(cur.top() * num[idx + 1]);
		sign[2]--;
		func(idx + 1);
		sign[2]++;
		cur.pop();
	}
	if (sign[3] > 0)
	{
		cur.push(cur.top() / num[idx + 1]);
		sign[3]--;
		func(idx + 1);
		sign[3]++;
		cur.pop();
	}



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;


	for (int i = 0; i < N; i++)
	{
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> sign[i];
	}
	cur.push(num[0]);

	func(0);

	cout << maxres << "\n" << minres;
	return 0;
}