#include<iostream>

using namespace std;

int main(){

    int size,t,temp;
    cin>>size>>t;
    int arr[size];
    for(int i=0;i<size;i++){
        cin>>temp;
        arr[i]=temp;
    }
    for (int i = 0; i < size; i++)
    {
        if(arr[i]<t)
            cout<<arr[i]<<" ";
    }
    
    return 0;
}