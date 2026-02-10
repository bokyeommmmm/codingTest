#include<iostream>
using namespace std;

int main()
{
    string a;
    cin>>a;
    for (int i = 0; i < a.length(); i++)
    {
        if(a[i]>='a')
            a[i]=a[i]-32;
        else
            a[i]=a[i]+32;
    }
    cout<<a;
    
}