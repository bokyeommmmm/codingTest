#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int calc1(int n, int m, const vector<vector<int>> arr) { //+
    int max_sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = arr[i][j];

            for (int k = 1; k < m; k++) {
                if (i - k >= 0) sum += arr[i - k][j]; 
                if (i + k < n)  sum += arr[i + k][j]; 
                if (j - k >= 0) sum += arr[i][j - k]; 
                if (j + k < n)  sum += arr[i][j + k];
            }
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}

int calc2(int n, int m, const vector<vector<int>> arr) { //X
    int max_sum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = arr[i][j]; 
            for (int k = 1; k < m; k++) {
                if (i - k >= 0 && j - k >= 0) sum += arr[i - k][j - k];
                if (i - k >= 0 && j + k < n)  sum += arr[i - k][j + k];
                if (i + k < n && j - k >= 0)  sum += arr[i + k][j - k];
                if (i + k < n && j + k < n)  sum += arr[i + k][j + k];
            }
            max_sum = max(max_sum, sum);
        }
    }
    return max_sum;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{

		int N,M;
        cin>>N>>M;
        vector<vector<int>> arr(N,vector<int>(N));
        int temp;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin>>temp;
                arr[i][j]=temp;
            }
            
        }
        int result1 = calc1(N, M, arr);
        int result2 = calc2(N, M, arr);
        
        cout << "#" << test_case << " " << max(result1, result2) << "\n";

	}
	return 0;
}