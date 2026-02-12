#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, A;
int res;
int dr[5] = { 0,0,1,0,-1 };
int dc[5] = { 0,-1,0,1,0 }; //이동x,상,우,하,좌
vector<pair<int, int>>bcrc;
vector<pair<int, int>>bcinfo;
int ar, ac, br, bc; //a의 {r,c} b의 {r,c}

void charge()
{
	vector<int>alist;
	vector<int>blist;
	int maxvol = 0;
	for (int i = 0; i < A; i++)
	{
		if ((abs(ar - bcrc[i].first) + abs(ac - bcrc[i].second)) <= bcinfo[i].first)//a가 i번째 bc 속하면
		{
			alist.push_back(i);
		}
		if ((abs(br - bcrc[i].first) + abs(bc - bcrc[i].second)) <= bcinfo[i].first)//b가 i번째 bc 속하면
		{
			blist.push_back(i);
		}
	}
	if (alist.size() != 0 && blist.size() != 0)
	{
		for (int i = 0; i < alist.size(); i++)
		{
			for (int j = 0; j < blist.size(); j++)
			{
				if (alist[i] == blist[j]) //같은데서 받는 경우
				{
					maxvol = max(maxvol, bcinfo[alist[i]].second);
				}
				else //다른데서 받는 경우 
				{
					maxvol = max(maxvol, bcinfo[alist[i]].second + bcinfo[blist[j]].second);
				}
			}
		}
	}
	else if ((alist.size() == 0 && blist.size() != 0))
	{
		for (int i = 0; i < blist.size(); i++)
		{
			maxvol = max(maxvol, bcinfo[blist[i]].second);
		}
	}
	else if ((alist.size() != 0 && blist.size() == 0))
	{
		for (int i = 0; i < alist.size(); i++)
		{
			maxvol = max(maxvol, bcinfo[alist[i]].second);
		}
	}
	res += maxvol;
}
void move(vector<int>&planA, vector<int>&planB)
{
	for (int i = 0; i < M; i++)
	{
		charge();
		ar = ar + dr[planA[i]];
		ac = ac + dc[planA[i]];
		br = br + dr[planB[i]];
		bc = bc + dc[planB[i]];
	}
	charge();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> M >> A;
		bcrc.clear();
		bcinfo.clear();

		vector<int>planA;
		vector<int>planB;
		ar = 0;
		ac = 0;
		br = 9;
		bc = 9;
		res = 0;
		for (int i = 0; i < M; i++)
		{
			int temp;
			cin >> temp;
			planA.push_back(temp);
		}
		for (int i = 0; i < M; i++)
		{
			int temp;
			cin >> temp;
			planB.push_back(temp);
		}

		for (int i = 0; i < A; i++)
		{
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			bcrc.push_back({ a - 1,b - 1 });
			bcinfo.push_back({ c,d });
		}

		move(planA, planB);
		cout << "#" << tc << " " << res << "\n";
	}
	return 0;
}