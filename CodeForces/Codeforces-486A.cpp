/*
     sum of first n even numbers = n (n + 1)
     sum of first n odd numbers  = n * n
*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    long long sum = 0;
    long long h = n / 2;
    if(n % 2 == 0){
        sum = h * (h + 1) - (h * h);
    }
    else{
        sum = h * (h + 1) - ((h + 1) * (h + 1));
    }
    cout<<sum<<endl;
}