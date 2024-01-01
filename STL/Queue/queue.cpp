#include<bits/stdc++.h>
using namespace std;
int main(){
    queue<string> q;
    q.push("love");
    q.push("respect");
    q.push("modesty");
    q.push("hate");

    cout<<"Size: "<<q.size()<<endl;
    cout<<"First element: "<<q.front()<<endl;
    
    q.pop();

    cout<<"After Pop first element: "<<q.front()<<endl;
}