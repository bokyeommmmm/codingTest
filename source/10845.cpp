#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    queue<int> arr;
    for (int i = 0; i < N; i++)
    {
        string str;
        cin>>str;

        if(str=="push")
        {
            int temp;
            cin>>temp;
            arr.push(temp);
        }
        else if(str == "front")
        {
            if(!arr.empty())
                cout<<arr.front()<<"\n";
            else
                cout<<-1<<"\n";
        }
        else if(str == "pop")
        {
            if(!arr.empty()){
                cout<<arr.front()<<"\n";
                arr.pop();}
            else
                cout<<-1<<"\n";
            
        }
        else if(str == "size")
        {
            cout<<arr.size()<<"\n";
        }
        else if(str == "empty")
        {
            if (arr.empty())
            {
                cout<<1<<"\n";
            }
            else
                cout<<0<<"\n";
            
        }
        else if(str == "back")
        {
            if (arr.empty())
            {
                cout<<-1<<"\n";
            }
            else
                cout<<arr.back()<<"\n";
        }
    }

}