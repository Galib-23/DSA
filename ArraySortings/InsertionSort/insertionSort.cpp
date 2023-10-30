#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {5, 4, 10, 1, 6, 2};
    int n = sizeof(a) / sizeof(a[0]);
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 and a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j+1] = temp; // because j-- was done j was one step previous of a[j]
    }
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}