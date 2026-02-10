#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int N,M;
    cin>>N>>M;
    int temp;
    vector<int> arr;
    int sum=0;
    int result=0;
    for(int i = 0; i<N ; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < N-2; i++)
    {
        for (int j = i+1; j < N-1; j++)
        {
       
            for (int k = i+2; k < N; k++)
            {
                sum=arr[i]+arr[j]+arr[k];
                if(sum>result&&sum<=M)
                        result=sum;
            }
        }
       
    }
    cout<<result;
}