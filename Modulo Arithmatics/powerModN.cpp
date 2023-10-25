/*
    (a+b) % n = (a%n + b%n) % n;
    (a*b) % n = (a%n * b%n) % n;
*/

#include<bits/stdc++.h>
using namespace std;

long long fastPower(long long a, long long b, long long n){
    long long res = 1;

    while(b>0){
        if((b&1) != 0){
            res = (res * a % n) % n;
        }
        a = (a % n * a % n) % n;
        b = b / 2; //b = b >> 1
    }
    return res;
}

int main(){
    long long a = 3978432;
    long long b = 5;
    long long n = 1000000007;
    long long result = fastPower(a, b, n);
    cout<<"result : "<<result<<endl;
}