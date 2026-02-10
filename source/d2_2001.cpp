#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int func(vector<vector<int>> arr,int N,int M){
    int maxSum =0;
    for (int i = 0; i <= N-M; i++)
    {
        for (int j = 0; j <= N-M; j++)
        {
            int sum = 0;
            for (int x = 0; x < M; x++) {
                for (int y = 0; y < M; y++) {
                    sum += arr[i + x][j + y];
                }
            }

            maxSum = max(maxSum, sum);
        }
        
    }
    return maxSum;
}
int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        vector<vector<int>> arr;
        int N;
        cin>>N;
        int M;
        cin>>M;
        for (int i = 0; i < N; i++)
        {
            vector<int> arr1;
            for (int j = 0; j < N; j++)
            {
                int temp;
                cin>>temp;
                arr1.push_back(temp);
            }
            arr.push_back(arr1);
        }
        
        cout<<"#"<<test_case<<" "<<func(arr,N,M)<<"\n";

    }
    return 0;
}