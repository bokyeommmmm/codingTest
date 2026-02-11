#include<iostream>
using namespace std;
int result = 0;

void isPrime(int n)
{
    for(int i = 2;i<n;i++){
        if(n%i==0)
        {
            return;
        }        
    }
    result++;

}
int main()
{
    int n=0;
    cin>>n;
    int temp;
    for (int i = 0 ; i < n; i++)
    {
        cin>>temp;
        if(temp>1)
            isPrime(temp);
    }
    cout<<result;
    return 0;
}