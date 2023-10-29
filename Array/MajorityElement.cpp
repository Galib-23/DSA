#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = { 2, 2, 1, 2, 2, 4, 7};  //in this case the number of element present in the array must be greater than n/2
    int size = sizeof(a)/sizeof(a[0]);
    int ansIndex = 0;
    int count = 1;
    for (int i = 1; i < size; i++)
    {
        if(a[i] == a[ansIndex]){
            count++;
        }
        else{
            count--;
        }
        if(count == 0){
            ansIndex = i;
            count = 1;
        }
    }
    cout<<"Majority element is : "<<a[ansIndex]<<endl;    
}