/*
Q. Find the two non repeating elements in an array: 

    a = [5, 4, 1, 4, 3, 5, 1, 2]
    res = 5 ^ 4 ^ 1 ^ 4 ^ 3 ^ 5 ^ 1 ^ 2
    As only 3 and 2 are non Repeating . So the result will be
    res = 3 ^ 2
    now 3 = 1 1
        2 = 1 0
    -------------
    so,3^2= 0 1(Find the last set bit of 3 ^ 2)
    let's say it's n'th bit.
    
    now separate the numbers in two different arrays:
    1. in one array whose nth bit is set
    2. in another array whose nth bit is unset 
    vecUnset = [4, 4, 2]
    vecSet = [5, 1, 3, 5, 1]
    now result ^ vecUnset = 3;
        result ^ vecSet = 2;
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[] = {5, 4, 1, 4, 3, 5, 1, 2};
    int size = sizeof(a)/sizeof(a[0]);
    int Xor = 0;
    for (int i = 0; i < size; i++)
    {
        Xor = Xor ^ a[i];
    }
    
    int MaskOfRightSetBit = Xor & (~Xor); // this is the formula for finding the mask of any number
    //for example mask of 11001000 is  --> 00001000
    int numA = 0;
    int numB = 0;
    for (int i = 0; i < size; i++)
    {
        if(a[i] & MaskOfRightSetBit == 0){
            numA = numA ^ a[i];
        }
        else{
            numB = numB ^ a[i];
        }
    }
    cout<<"The numbers are : "<<numA<<" and "<<numB<<endl;
    
}