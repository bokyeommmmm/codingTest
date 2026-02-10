#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int num = 0;
    vector<string> str;
    string temp;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>temp;
        str.push_back(temp);
    }
    for(int i= 0;i<num;i++){
        cout<<str[i][0]<<str[i][str[i].length()-1]<<"\n";
    }
}