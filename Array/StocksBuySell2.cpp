/*
    Q. This is same as stock buy and sell just difference is that here we can buy and sell as many times as we want.
*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {5, 2, 6, 1, 4, 7, 3, 6};
    int size = sizeof(a)/sizeof(a[0]);
    int profit = 0;
    for (int i = 1; i < size; i++)
    {
        if(a[i] > a[i - 1]){
            profit += (a[i] - a[i-1]);
        }
    }
    cout<<"The maximum profit is : "<<profit<<endl;
}