#include<iostream>
#include<vector>
#include<set>
using namespace std;

int N, M, res;
set<int>truth;
vector<vector<int>>party;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;
	int num;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		int temp;
		cin >> temp;
		truth.insert(temp); //진실을 아는 사람들. 
	}
	party.assign(M,vector<int>());
	for (int i = 0; i < M; i++)
	{
		int temp;
		cin >> temp;
		for (int j = 0; j < temp; j++)
		{
			int temp2;
			cin >> temp2;
			party[i].push_back(temp2); //i번 파티에 사람 추가. 
		}
	}
	bool isDone = false;
	while (!isDone)
	{
		isDone = true;
		for (int i = 0; i < M; i++) //모든 파티 다 돌면서 
		{
			for (int j = 0; j < party[i].size(); j++)
			{
				if (truth.count(party[i][j]) != 0) //진실 아는사람 있으면
				{
					for (int k = 0; k < party[i].size(); k++) //그 파티에서
					{
						if (truth.count(party[i][k]) == 0) //모르는 사람 있었을때. 
						{
							truth.insert(party[i][k]); // 진실 알려주고
							isDone = false;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		bool canTalk = true;
		for (int j = 0; j < party[i].size(); j++)
		{
			if (truth.count(party[i][j]) != 0) //진실을 아는 사람이 있다면
			{
				canTalk = false;
				break;
			}
		}
		if (canTalk)res++;
	}
	cout << res;

	return 0;
}