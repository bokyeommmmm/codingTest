#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
    int num =0;
    int size[6]={0};
    int t,p=0;
    int tSet=0;
    int pSet=0;
    int pOne=0;

    cin>>num;
    for(int i = 0;i<6;i++){
        cin>>size[i];
    }
    cin>>t>>p;
    for(int i = 0 ;i<6;i++)
    {
        if(size[i]>0)
        {
            if(size[i]%t==0){
                tSet=tSet+(size[i]/t);
            }
            else if(size[i]%t>0){
                tSet=tSet+(size[i]/t)+1;
            }
        }
    }
    pSet=num/p;
    pOne=num%p;
    cout<<tSet<<endl<<pSet<<" "<<pOne;
    return 0;
}