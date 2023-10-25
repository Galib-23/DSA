/*
    a ^ b = (a ^ 2) ^ b/2  --> if b is even
    a ^ b = a.a ^ b-1  -->  if b is odd
*/

#include<bits/stdc++.h>
using namespace std;

int fastPower(int a, int b){
    int res = 1;

    while(b>0){
        if((b&1) != 0){
            res = res * a;
        }
        a = a * a;
        b = b / 2; //b = b >> 1
    }
    return res;
}

int main(){
    int a = 5;
    int b = 3;
    int result = fastPower(a, b);
    cout<<"result : "<<result<<endl;
}