#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> arr;
    int amt,temp;
    cin>>amt;
    for (int i = 0; i < amt; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }
    sort(arr.begin(),arr.end());
    
    for(int i = 0 ; i < amt;i++)
    {
        cout<<arr[i]<<"\n";
    }
    
    
}