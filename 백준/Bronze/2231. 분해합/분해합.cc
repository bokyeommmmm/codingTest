#include<iostream>
using namespace std;
int func(int n){
    int sum=0;
    int div=1000000;
    for (int i = 0; i <7; i++)
    {
        sum+=n/div;
        n%=div;
        div/=10;
    }
    return sum;
}
int main(){

    int N;
    cin>>N;
    int res = 0;
    for (int i = 1; i < N; i++)
    {
        if (i+func(i)==N)
        {
            res=i;
            break;
        }
    }
    cout<<res;
    return 0;
}