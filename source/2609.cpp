#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

void func1(int a, int b){
    int res = 1;
    for(int i = 1;i<=b; i++){
        if(a%i==0&&b%i==0)
            res=i;
    }
    cout<<res<<endl;
}
void func2(int a, int b){
    int res = a*b;
    for(int i = a*b;i>=a; i--){
        if(i%a==0&&i%b==0)
            res=i;
    }
    cout<<res<<endl;
}
int main()
{
    int A,B;
    cin>>A>>B;
    if(A>B){
        func1(A,B);
        func2(A,B);
    }
    else{
        func1(B,A);
        func2(B,A);
    }
}