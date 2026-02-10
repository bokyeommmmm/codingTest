#include<iostream>
#include<cmath>
#include<vector>
#include<iomanip>
#include<algorithm>
using namespace std;

int main()
{
    float m,temp ;
    vector<float> score;
    float sum = 0.0;
    cin>>m;
    for(int i =0 ; i< m;i++)
    {
        cin>>temp;
        score.push_back(temp);
    }
    sort(score.begin(),score.end());
    float weight = 100/score[m-1];
    for(int i =0 ; i< m;i++)
    {
        sum+=score[i]*weight;
    }
    cout<<fixed<<showpoint<<sum/m;
}