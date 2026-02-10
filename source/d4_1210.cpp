#include <iostream>
#include <vector>

using namespace std;

int dx[3] = {0, 0, -1}; // 좌 우 위
int dy[3] = {-1, 1, 0};

int func(vector<vector<int>> &ladder, int x, int y)
{

   
        if(y-1>=0&&ladder[x][y-1]==1) //왼쪽있으면 왼쪽
        {
            ladder[x][y]=0;
            return func(ladder,x,y-1);
        }
        else if(y+1<100&&ladder[x][y+1]==1)
        {
            ladder[x][y]=0;

            return func(ladder,x,y+1);
        }
        else
        {
            if(x==0)
                return y;
            return func(ladder,x-1,y);
        }
        
    
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 1; tc <= 10; tc++)
    {
        int a;
        cin >> a;
        int res = 0;
        vector<vector<int>> ladder(100, vector<int>(100, 0));
        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                cin >> ladder[i][j];
            }
        }

        for (int j = 0; j < 100; j++)
        {
            if (ladder[99][j] == 2)
            {
                res = func(ladder, 99, j);
            }
        }
        cout<<"#"<<tc<<" "<<res<<"\n";
    }

    return 0;
}