#include<iostream>

using namespace std;

int dp[101]={0,1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main()
{

    for (size_t i = 11; i <= 100; i++)
    {
        dp[i] = dp[i-1]+dp[i-3];
    }
    
    int T;
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        int a;
        cin>>a;
        cout<<dp[a]<<"\n";
    }
    

}