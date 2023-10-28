/*
    Q. Number of ways to move to a definite block of a matrix from an initial block.

    Base Case: When row is 1 or column is one. Cause in both case number of ways is one.
*/

#include<bits/stdc++.h>
using namespace std;
int numberOfWays(int n, int m){
    if(n == 1 || m == 1){
        return 1;
    }
    return numberOfWays(n-1, m) + numberOfWays(n, m-1);
}
int main(){
    int n, m;
    cout<<"Enter the number of rows: ";
    cin>>n;
    cout<<"Enter the number of cols: ";
    cin>>m;
    int result = numberOfWays(n, m);
    cout<<"Result is : "<<result<<endl;

}