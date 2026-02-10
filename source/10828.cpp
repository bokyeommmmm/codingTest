#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin>>str;

        if(str=="push")
        {
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        else if(str == "pop")
        {
            if (arr.size()==0)
            {
                cout<<-1<<"\n";
            }
            else
            {
            cout<<arr[arr.size()-1]<<"\n";
            arr.pop_back();
            }
        }
        else if(str == "size")
        {
            cout<<arr.size()<<"\n";
        }
        else if(str == "empty")
        {
            if (arr.size()==0)
            {
                cout<<1<<"\n";
            }
            else
                cout<<0<<"\n";
            
        }
        else if(str == "top")
        {
            if (arr.size()==0)
            {
                cout<<-1<<"\n";
            }
            else
            {
                cout<<arr[arr.size()-1]<<"\n";
            }
        }
    }

}