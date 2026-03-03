#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
using namespace std;

int A, B, res;

queue<int>q;
map<int,int>dist;

void bfs()
{
	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		if (temp == A)
		{
			break;
		}
		if (temp < A)
		{
			continue;
		}
		int next;
		if(temp%10==1)
		{
			
			next = temp / 10 ;
			if (temp / 10 < 10)
			{
				next = temp / 10;
			}
			if (dist.count(next)==0)
			{
				dist.insert({ next,dist[temp] + 1 });
				q.push(next);
			}
		}
		if (temp % 2 == 0)
		{
			next = temp / 2;
			if (dist.count(next) == 0)
			{
				dist.insert({ next,dist[temp] + 1 });
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> A >> B;
	res = 2100000000;
	q.push(B);
	dist.insert({ B,1 });
	bfs();
	if (dist.count(A)==0)
	{
		cout << -1 << "\n";
		return 0;
	}
	cout << dist[A] << "\n";
	return 0;
}