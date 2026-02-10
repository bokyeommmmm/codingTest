#include<iostream>
#include<stack>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin>>N;
    stack<int> stk;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin>>temp;
        if (temp==0)
        {
            stk.pop();
        }
        else
            stk.push(temp);
    }
    int sum = 0;
    while (!stk.empty())
    {
        sum+=stk.top();
        stk.pop();
    }
    cout<<sum;
    

}