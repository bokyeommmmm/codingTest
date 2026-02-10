#include <iostream>
#include <vector>
#include <string>
using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int N,M;
vector<vector<int>> map;
vector<vector<int>> visited;

void dfs()
{
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>M;

    map.assign(N,vector<int>(M,0));
    visited.assign(N,vector<int>(M,0));


    return 0;
}
