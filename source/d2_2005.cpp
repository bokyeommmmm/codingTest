#include<iostream>
#include<vector>
using namespace std;
void func(vector<vector<int>> &arr, int N){
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout<<arr[i][j]<<" ";
        }
            cout<<"\n";        
    }

}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_case;
	int T;
	
	cin>>T;

    vector<vector<int>> arr(10,vector<int>(10));
    arr[0][0]=1;

    for (int i = 1; i < 10; i++)
        {
            arr[i][0]=1;
            arr[i][i]=1;
            for (int j = 1; j < i; j++)
            {
                arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
            }
            
        }
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int N;
        cin>>N;

        cout<<"#"<<test_case<<"\n";
        func(arr,N);

	}
	return 0;
}