#include<iostream>

using namespace std;

int main()
{
   int dp[1000001]={};
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;
    for (int i = 4; i <= 100000; i++)
    {
        dp[i] = dp[i-1]+1 , dp[i/2]+1,dp[i/3]+1;
    }
    
}