#include<iostream>
#include<vector>
using namespace std;

string isRight(string str)
{
    for(int i =0;i<str.length()/2;i++){
        if(str[i]!=str[str.length()-i-1])
            return "no";
    }
    return "yes";

}

int main()
{
    string temp;
    vector<string> arr;
    for (;;)
    {
        cin>>temp;
        if(temp=="0")
            break;
        arr.push_back(isRight(temp));
    }
    for(int i = 0 ; i<arr.size();i++)
    {
        cout<<arr[i]<<"\n";
    }
}