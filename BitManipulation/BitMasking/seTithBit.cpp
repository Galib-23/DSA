/*
n =      1 0 0 1 1 0 1 0 1
(1<<i) = 0 0 0 0 0 1 0 0 0    (For i = 3 for[0,1,2,3] convention) 

setting ith bit would be logical or between n and (1<<i)

*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n = 10;
    int i = 0;
    int mask = (1 << i);
    int result = n | mask;
    cout<<"Setting "<<i<<"th bit of "<<n<<" it becomes : "<<result<<endl;
}