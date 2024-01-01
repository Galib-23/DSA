#include<bits/stdc++.h>
using namespace std;
int main(){

    //max heap
    priority_queue<int> maxq; //returns maximum element

    //min heap
    priority_queue<int , vector<int>, greater<int>> minq;

    maxq.push(1);
    maxq.push(2);
    maxq.push(3);
    maxq.push(4);
    int n = maxq.size();

    cout<<"max heap: "<<endl;
    for(int i = 0; i< n ; i++){
        cout<<maxq.top()<<" ";
        maxq.pop();
    }cout<<endl;

    minq.push(1);
    minq.push(2);
    minq.push(3);
    minq.push(4);
    int nm = minq.size();

    cout<<"Min Heap: "<<endl;
    for(int i = 0; i< nm ; i++){
        cout<<minq.top()<<" ";
        minq.pop();
    }cout<<endl;

}