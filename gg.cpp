#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n>>k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    sort(a, a + n);
    int count = 0;
    int team = 0;
    for (int i = 0; i < n; i++)
    {
        if(a[i] + k <= 5){
            count++;
        }else break;
        if(count == 3){
            team++;
            count = 0;
        }
    }
    cout<<team<<endl;
    
}