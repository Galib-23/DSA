/*
     Q. There are n people making a circle. They want to play a game. Starting from the people at index 0 they will kill the person at k'th distance from them and the gun will be delivered to the k+1'th person . Doing this until the last man stands. Find the position of the last man alive.

    link: https://youtu.be/fZ3p2Iw-O2I?feature=shared
*/

#include<bits/stdc++.h>
using namespace std;

int jos(int n, int k){
    if(n == 1){
        return 0;
    }
    return (jos(n-1, k) + k) % n; //+k because the kth man is being killed
}

int main(){
    int result = jos(7, 3);
    cout<<"Result is : "<<result<<endl;
}