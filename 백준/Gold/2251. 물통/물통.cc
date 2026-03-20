#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int A, B, C;
int maxA, maxB, maxC;
vector<vector<int>>visited;
vector<int>res;

void dfs()
{
	int tempA, tempB, tempC;
	tempA = A;
	tempB = B;
	tempC = C;

	// A -> B
	if (A > 0 && B < maxB)
	{
		int move = min(A, maxB - B);
		A -= move;
		B += move;
		if (visited[A][B] != 1)
		{
			visited[A][B] = 1;
			if (A == 0) res.push_back(C);
			dfs();
		}
	}
	A = tempA; B = tempB; C = tempC;

	// A -> C
	if (A > 0 && C < maxC)
	{
		int move = min(A, maxC - C);
		A -= move;
		C += move;
		if (visited[A][B] != 1)
		{
			visited[A][B] = 1;
			if (A == 0) res.push_back(C);
			dfs();
		}
	}
	A = tempA; B = tempB; C = tempC;

	// B -> A
	if (B > 0 && A < maxA)
	{
		int move = min(B, maxA - A);
		B -= move;
		A += move;
		if (visited[A][B] != 1)
		{
			visited[A][B] = 1;
			if (A == 0) res.push_back(C);
			dfs();
		}
	}
	A = tempA; B = tempB; C = tempC;

	// B -> C
	if (B > 0 && C < maxC)
	{
		int move = min(B, maxC - C);
		B -= move;
		C += move;
		if (visited[A][B] != 1)
		{
			visited[A][B] = 1;
			if (A == 0) res.push_back(C);
			dfs();
		}
	}
	A = tempA; B = tempB; C = tempC;

	// C -> A
	if (C > 0 && A < maxA)
	{
		int move = min(C, maxA - A);
		C -= move;
		A += move;
		if (visited[A][B] != 1)
		{
			visited[A][B] = 1;
			if (A == 0) res.push_back(C);
			dfs();
		}
	}
	A = tempA; B = tempB; C = tempC;

	// C -> B
	if (C > 0 && B < maxB)
	{
		int move = min(C, maxB - B);
		C -= move;
		B += move;
		if (visited[A][B] != 1)
		{
			visited[A][B] = 1;
			if (A == 0) res.push_back(C);
			dfs();
		}
	}
	A = tempA; B = tempB; C = tempC;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> maxA >> maxB >> maxC;
	A = 0;
	B = 0;
	C = maxC;
	visited.assign(maxA+1, vector<int>(maxB+1, -1));

	C = maxC;
	visited[0][0] = 1;
	res.push_back(C);

	dfs();
	sort(res.begin(), res.end());

	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}