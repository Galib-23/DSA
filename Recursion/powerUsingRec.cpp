#include<bits/stdc++.h>
using namespace std;
int power(int a, int b){
    if(b == 0) return 1; // Top of the stack
    return a * power(a, b-1);
}
int main(){
    cout<<"a to the power b: "<<power(4, 2)<<endl;
}
/*
    For example, let's say you want to calculate power(2, 3). Here's how the recursion would unfold:

    power(2, 3) calls power(2, 2) because b is decremented by 1.
    power(2, 2) calls power(2, 1) for the same reason.
    power(2, 1) calls power(2, 0) as b becomes 0.
    At this point, the base case is reached. When b is 0, the function returns 1. So:

    power(2, 0) returns 1.
    Now, the previous calls can start returning values:

    power(2, 1) returns 2 * 1 = 2 (it multiplies a by the result of the recursive call with b-1).
    power(2, 2) returns 2 * 2 = 4.
    power(2, 3) returns 2 * 4 = 8.
*/