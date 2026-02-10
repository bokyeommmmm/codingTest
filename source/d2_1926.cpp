#include<iostream>
#include<string>
using namespace std;

void func(int N)
{
    int cnt = 0;
    string str = to_string(N);
    for (int i = 0; i < (int)str.size(); i++)
    {
        if(str[i] == '3' || str[i] == '6' || str[i] == '9')
            {
                cnt++;
            }
    }
    if (cnt==0)
    {
        cout<<N<<" ";
    }
    else
    {
        for (int i = 0; i < cnt; i++)
        {
            cout<<"-";
        }
        cout<<" ";
        
    }
    
    
}
int main(int argc, char** argv)
{
    int N;
    cin>>N;

    for (int i = 1; i <= N; i++)
    {
        func(i);
    }
    
    return 0;
}