#include<iostream>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int len[6];
	int dir[6];

	int amt;
	cin >> amt;
	int area = 0;
	for (int i = 0; i < 6; i++)
	{
		cin >> dir[i] >> len[i];
	}
	int Mlen = 0, Mlen2 = 0;
	int Midx = 0, Midx2 = 0;

	for (int i = 0; i < 6; i=i+2)
	{
		if (Mlen < len[i])
		{
			Mlen = len[i];
			Midx = i;
		}
	}

	for (int i = 1; i < 6; i = i + 2)
	{
		if (Mlen2 < len[i])
		{
			Mlen2 = len[i];
			Midx2 = i;
		}
	}
	int area1 = Mlen * Mlen2;
	int area2 = len[(Midx + 3) % 6] * len[(Midx2 + 3) % 6];
	cout << (area1 - area2)*amt;

	return 0;
}