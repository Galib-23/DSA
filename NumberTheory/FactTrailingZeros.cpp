/*
    Q. A number given n . Find out How many trailing zeros are there in the factorial of n.

    SOl: We have to find how many times five repeats in the factorial of any number.
    Because  5 * 2 makes it 10. and why we are looking for only 5 not 2 because 2 will must repeat
    more than 5. and 10 consists of (2 * 5)
    
    That means we will be looking for 5, 25, 125, 625 ... and so on
*/
#include<bits/stdc++.h>
using namespace std;
int main () {
    int n = 12;
    int result = 0;
    for (int i = 5; i <= n; i*=5)
    {
        result = result + n/i;
    }
    cout<<"Number of trailing 0's is : "<<result<<endl;
    
}