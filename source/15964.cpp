#include<iostream>
using namespace std;

long long func(int x,int y){
return (x+y)*(x-y);
}
int main()
{
    long long A,B;
    cin>>A>>B;
    cout<<func(A,B);

    return 0;
}