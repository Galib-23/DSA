#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    if(s.find(5) == s.end()){
        cout<<"Not found"<<endl; //s.find returns an iterator. So if the iterator has reached the end that means it's not found
    }
    else cout<<"Found"<<endl;

    //iteration
    for(auto it = s.begin(); it != s.end();){
        cout<<(*it)<<" ";
    }
}