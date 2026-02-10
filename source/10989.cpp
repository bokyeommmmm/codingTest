#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int count[10001]={0};

    int N;
    cin>>N;
    int temp;
    for (int i = 0; i < N; i++)
    {
        cin>>temp;
        count[temp]++;
    }
    for(int i = 0 ; i< 10001;i++)
    {
        for (int j = 0; j < count[i]; j++)
        {
            cout<<i<<"\n";
        }
        
    }
    
    return 0;
}
