#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 10; //(1010)
    int i = 1;
    int mask = (1<<i); //(0010)
    int maskInverted = ~mask; //(1101)
    int result = n & maskInverted;
    cout<<result<<endl;
}