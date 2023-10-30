#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {4, 2, 1, 3, 5};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 0; i < n - 1; i++)
    {
        int flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            
            if(a[j] > a[j + 1]){
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
        if(flag == 0) break;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}