#include<iostream>
using namespace std;

int func(long long x, long long y, long long N){
    int cnt=0;
    for(;;){
        if(x>y){
            y+=x;
            cnt++;
        }
        else{
            x+=y;
            cnt++;
        }
        if(y>N||x>N){
            return cnt;
        }
    }
    
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{

        long long x,y,N;
        cin>>x>>y>>N;

        cout<<func(x,y,N)<<"\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}