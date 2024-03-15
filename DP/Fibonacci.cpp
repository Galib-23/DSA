#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int dp[N];

int fib( int n ){
    if(n == 0) return 0;
    if(n == 1) return 1;
    if(dp[n] != -1) return dp[n];
    dp[n] = fib(n - 1) + fib(n - 2);
    return dp[n];
}

int main(){
    memset(dp, -1, N);
    int result = fib(7);
    cout<<result<<endl;
}