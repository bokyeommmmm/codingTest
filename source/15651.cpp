#include<iostream>

using namespace std;

int N,M;

void ferm(int cnt)
{
    if (cnt==N)
    {
        cout<<"\n";
        return;
    }
    for (int i = 1; i <= N; i++)
    {
        cout<<i<<" ";
        ferm(cnt+1);
    }
    
    
}

int main()
{

    cin>>N>>M;
    ferm(0);

    return 0;
}