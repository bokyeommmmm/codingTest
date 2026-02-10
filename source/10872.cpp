#include<iostream>
using namespace std;

int fact(int n){
    if(n>1)
        return fact(n-1)*n;
    else
        return 1;

}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}