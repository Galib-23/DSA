/*
    1. GCD(a, b) = GCD(a - b, b) where a > b;
    2. GCD(a, b) = GCD(b, a % b);
*/

#include<bits/stdc++.h>
using namespace std;

int GCD(int a, int b){

    if(b == 0) return a;
    return GCD(b, a % b);
}

int main(){
    cout<<"GCD is : "<<GCD(15, 27)<<endl;
}