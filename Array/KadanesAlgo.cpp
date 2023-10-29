/*
    Q. Find the sub array of any given array whose sum is maximum.
*/
#include<bits/stdc++.h>
using namespace std;
int kadanesSum(int a[], int size){
    int sum = 0;
    int maxSum = a[0];
    for (int i = 0; i < size; i++)
    {
        sum = sum + a[i];
        maxSum = max(maxSum, sum);
        if(sum < 0){
            sum = 0;
        }
    }
    return maxSum;
}
int main(){
    int a[] = {1, 2, -4, 5, -5, 7};
    int size = sizeof(a) / sizeof(a[0]);
    int result = kadanesSum(a, size);
    cout<<"Sum is : "<<result<<endl;
}