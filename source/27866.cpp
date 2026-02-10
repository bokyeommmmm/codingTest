#include<iostream>
using namespace std;

int main()
{
    string str;
    int idx;
    getline(cin,str);
    cin>>idx;
    cout<<str[idx-1];

    return 0;
}