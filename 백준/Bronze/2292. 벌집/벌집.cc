#include<iostream>

using namespace std;

int main()
{
    int N;
    int res=1;
    int x=1;
    cin>>N;
    for(int i = 1;;i++){
        if(N<=x){
            cout<<res;
            break;
        }
        else
        {
            x+=6*i;
            res++;    
        }
    }
    return 0;
}