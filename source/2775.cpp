#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int T;
    cin>>T;
    int k,n;
    int arr[15][15]={0};
    vector<int>res;
    for (int i = 0 ;i<15 ; i++){
        arr[0][i]=i+1;
        arr[i][0]=1;
    }
    for (int i = 1; i < 15; i++)
    {
        for (int j = 1; j < 14; j++)
        {
            arr[i][j]=arr[i-1][j]+arr[i][j-1];
        }
        
    }

    for (int i = 0; i < T; i++)
    {
        cin>>k>>n;
        res.push_back(arr[k][n-1]);
    }
    for (int i = 0; i < T; i++)
    {
        cout<<res[i]<<"\n";
    }
    
    
    
    return 0;
}