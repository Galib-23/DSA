#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int x = 0;
    string arrStr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arrStr[i];
    }
    for (int i = 0; i < n; i++)
    {
        string tempStr;
        tempStr = arrStr[i];
        if(tempStr[1] == '+'){
            x++;
        }else x--;
    }
    cout<<x<<endl;
}