#include<iostream>
using namespace std;

int main() {
    int M,N,temp;

    cin>>M>>N;
    int A[M][N];
    int B[M][N];
    int res[M][N];
    for(int i =0;i<M;i++){
        for (int j = 0; j<N; j++)
        {
            cin>>temp;
            A[i][j]=temp;
        }
        
    }
    for(int i =0;i<M;i++){
        for (int j = 0; j<N; j++)
        {
            cin>>temp;
            B[i][j]=temp;
        }
    }
    for(int i =0;i<M;i++){
        for (int j = 0; j<N; j++)
        {
            res[i][j]=A[i][j]+B[i][j];
        }
    }
    for(int i =0;i<M;i++){
        for (int j = 0; j<N; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}