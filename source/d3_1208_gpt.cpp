#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for (int tc = 1; tc <= 10; tc++)
    {
        vector <int>arr(101);
        int dump=0;
        cin>>dump;
        int maxh=1;
        int minh=101;
        for (int i = 0; i < 100; i++)
        {
            int h;
            cin>>h;
            arr[h]++; //h 높이 건물 개수. 
            if (h>maxh)
            {
                maxh=h;
            }
            if (h<minh)
            {
                minh=h;
            }
            
            
        }

        for (size_t i = 0; i < dump; i++)
        {
            if (arr[maxh]==0)
            {
                maxh--;
            }
            if (arr[minh]==0)
            {
                minh++;
            }
            if(minh==maxh)
                break;
            
            arr[maxh]--;
            arr[maxh-1]++;
            arr[minh]++;
            arr[minh+1]++;
        }
        
        

        cout << "#" << tc << " " << maxh-minh << "\n";
    }
    return 0;
}
