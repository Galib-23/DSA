
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 5;
    int b = 7;
    a = a ^ b;
    b = a ^ b; 
    a = a ^ b;
    //This can be verified by TRUTH TABLE
    cout<<"a is : "<<a<<endl;
    cout<<"b is : "<<b<<endl;
}