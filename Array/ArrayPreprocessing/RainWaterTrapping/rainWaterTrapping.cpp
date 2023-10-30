#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {3, 1, 2, 4, 0, 1, 3, 2};
    int size = sizeof(a) / sizeof(a[0]);
    int left[size];
    int right[size];
    left[0] = a[0];
    for (int i = 1; i < size; i++)
    {
        left[i] = max(left[i-1], a[i]);
    }
    right[size - 1] = a[size - 1];
    for (int i = size - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], a[i]);
    }
    int res = 0;
    for (int i = 0; i < size; i++)
    {
        res += (min(left[i], right[i])) - a[i];
    }
    cout<<"Total Rain Caught is : "<<res<<endl;
}