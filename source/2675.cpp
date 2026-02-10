#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);
   int tc;
   cin>>tc;
   for (int a = 0; a < tc; a++)
   {
        string S;
        string P;
        int R;
        cin>>R;
        cin>>S;

        for (int i = 0; i < S.size(); i++)
        {
            for (int j = 0; j < R; j++)
            {
                P.push_back(S[i]);
            }
        }
    cout<<P<<"\n";
    }
   return 0;   
}