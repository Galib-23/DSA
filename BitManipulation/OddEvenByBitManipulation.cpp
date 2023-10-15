
// Theory:
// The Last bit of all the even numbers are 0
// and the last bit of all odd numbers are 1

#include<bits/stdc++.h>
using namespace std;
int main(){
    int a = 3;
    if(a & 1 == 0){
        cout<<"The number is even"<<endl;
    }
    else {
        cout<<"The number is odd"<<endl;
    }
}