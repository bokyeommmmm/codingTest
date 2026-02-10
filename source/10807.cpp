#include<iostream>
using namespace std;

int main()
{
    int size,val,cnt,temp=0;
    cin>>size;

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin>>temp;
        arr[i]=temp;
    }
    cin>>val;
    cnt=0;
    for (int i = 0; i < size; i++)
    {

        if(arr[i]==val)
            cnt++;
    }
    cout<<cnt;

    return 0;
}