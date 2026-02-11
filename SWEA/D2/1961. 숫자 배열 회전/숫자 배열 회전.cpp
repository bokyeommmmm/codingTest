#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> rotate(vector<vector<int>> arr) {
    int n = arr.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = arr[n-1-j][i];
        }
    }
    return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
    int N;
    int temp;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin>>N;
        vector<vector<int>> arr(N, vector<int>(N)); 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin>>temp;
                arr[i][j]=temp;
            }
            
        }
        vector<vector<int>> arr90 = rotate(arr);
        vector<vector<int>> arr180 = rotate(arr90);
        vector<vector<int>> arr270 = rotate(arr180);

        cout<<"#"<<test_case<<"\n";
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++) cout << arr90[i][j];
            cout << " ";
            for (int j = 0; j < N; j++) cout << arr180[i][j];
            cout << " ";
            for (int j = 0; j < N; j++) cout << arr270[i][j];
            cout << "\n"; 
        }
	}
	return 0;
}