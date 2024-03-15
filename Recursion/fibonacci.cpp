#include<bits/stdc++.h>
using namespace std;

int fibo(int n){ // returns n'th fibonacci number
    if(n == 0) return 0;
    if(n == 1) return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main(){
    int res = fibo(5);
    cout<<res<<endl;
}