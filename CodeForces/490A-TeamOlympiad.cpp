#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    vector<vector<int>> v(4);
    v[0].push_back(0);
    v[1].push_back(0);
    v[2].push_back(0);
    v[3].push_back(0);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        if(a[i] == 1){
            count1++;
            v[1].push_back(i+1);
        }else if(a[i] == 2){
            count2++;
            v[2].push_back(i+1);
        }else{
            v[3].push_back(i+1);
            count3++;
        }
    }
    int m = min(count1, count2);
    int team = min(m, count3);
    sort(a, a + n);
    cout<<team<<endl;
    for (int i = 1; i <= team; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            cout<<v[j][i]<<" ";
        }
        cout<<endl;
    }
}