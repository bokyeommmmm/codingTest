#include<iostream>
#include<cmath>
using namespace std;

long long fact(long long n){
    if(n<2)
        return 1;
    return n*fact(n-1);
}
long long func1(long long n,long long k){
    if(k==0)
        return 1;
    return n*func1(n-1,k-1);
}

int main(){
    long long  N,K;
    cin>>N>>K;

    cout<<func1(N,K)/fact(K);
    return 0;
}