/*
    a = [1 ,2 ,2, 3, 4, 5, 4, 5, 1]
    int res = 1 ^ 2 ^ 2 ^ 3 ^ 4 ^ 5 ^ 4 ^ 5 ^ 1
    as we know that n ^ n = 0
    so in result the repeatative elements will ultimately become 0
    so the remaining element would be the only non repeating element 
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {1, 2, 2, 3, 4, 5, 4, 5, 1};
    int size = sizeof(a)/sizeof(a[0]);
    int result = a[0];
    for(int i = 1; i < size; i++){
        result = result ^ a[i];
    }
    cout<<"Result : "<<result<<endl;
}