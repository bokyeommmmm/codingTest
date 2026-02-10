#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string S;
    cin>>S;
    
    for (int  i = 0; i < S.length(); i++)
    {
        S[i]=toupper(S[i]);
    }
    int arr[26]={0};

    for (int i = 0; i < S.length(); i++)
    {
        arr[S[i]-'A']++;
    }
    int maxVal=0;
    for (int i = 0; i < 26; i++)
    {
        maxVal=max(maxVal,arr[i]);
    }
    int idx = 0;
    int cnt=0;
    for (int i = 0; i < 26; i++)
    {
        if (arr[i]==maxVal)
        {
            idx=i;
            cnt++;
            if(cnt>=2)
            {
                cout<<"?";
                return 0;
            }
        }
    }
    cout<<(char)('A'+idx);
    
    return 0;
}