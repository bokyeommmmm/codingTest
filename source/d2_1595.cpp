#include<iostream>
#include<vector>
#include<algorithm>
#include <climits>
using namespace std;

int main(int argc, char** argv)
{
    int T,N,M;

    cin>>T;
    vector<int> result;
    for (int i = 0; i < T; i++)
    {
        cin>>N>>M;
        vector<int> A;
        vector<int> B;
        int temp;

        for (int j = 0; j < N; j++)
        {
            cin>>temp;
            A.push_back(temp);
        }
        for (int j = 0; j < M; j++)
        {
            cin>>temp;
            B.push_back(temp);
        }       

        int max_ = INT_MIN;

        if(N<M)
        {
            for (int j = 0; j <= M-N; j++)
            {
                int temp1 = 0;
                for (int k = 0; k < N; k++)
                {
                    temp1 += A[k]*B[j+k];
                }
                max_=max(max_,temp1);
            }
            
        }
        else
        {
            for (int j = 0; j <= N-M; j++)
            {
                int temp1 = 0;
                for (int k = 0; k < M; k++)
                {
                    temp1 += A[j+k]*B[k];
                }
                max_=max(max_,temp1);
            }
        }
        result.push_back(max_);
    }
    
    for (int i = 1; i <= T; i++)
    {
        cout<<"#"<<i<<" "<<result[i-1]<<"\n";
    }
    
    return 0;
}