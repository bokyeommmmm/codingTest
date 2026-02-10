#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int argc, char** argv)
{
   ios::sync_with_stdio(false);
   cin.tie(NULL);

   string S;
   cin>>S;
   int arr[26];
   for (int i = 0; i < 26; i++)
   {
    arr[i]=-1;
   }
   for (int i = 0; i < S.length(); i++)
   {
        if (arr[S[i]-'a']==-1)
        {
            arr[S[i]-'a']=i;
        }
        
   }
   for (int i = 0; i < 26; i++)
   {
    cout<<arr[i]<<" ";
   }
   
   return 0;   
}