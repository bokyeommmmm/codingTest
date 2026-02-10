#include<iostream>
using namespace std;

int main()
{
    long A,B;
    cin>>A>>B;

    if(A>=B)
        cout<<A-B;
    else
        cout<<B-A;
    return 0;
}