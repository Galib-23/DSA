/*
Q. Lets Say I wanna check if 5th bit is 0 or 1.

bitPos: 8 7 6 5 4 3 2 1 0
n  -->  1 0 0 1 1 0 1 0 1
mask--> 0 0 0 1 0 0 0 0 0 (This is made by 1 << i where i = 5 for this case)
--------------------------
(&)oper:0 0 0 1 0 0 0 0 0

*/
#include<bits/stdc++.h>
using namespace std;

bool isBitSet(int num, int i){
    int mask = 1 << i;
    if((num & mask) != 0){
        return true;
    }
    else return false;
}

int main () {
    int num, i;
    cout<<"Enter the number: ";
    cin>>num;
    cout<<"Enter the position: ";
    cin>>i;
    if(isBitSet(num, i)){
        cout<<"The bit is 1"<<endl;
    }
    else{
        cout<<"The bit is 0"<<endl;
    }
}