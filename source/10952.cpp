#include<iostream>
using namespace std;

int main()
{
    int a,b;
    for(;;)
    {
if (!(cin >> a >> b)) break;  
        cout<<a+b<<"\n";
    }
    return 0;
}