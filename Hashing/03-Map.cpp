#include<bits/stdc++.h>
using namespace std;
int main(){

/*
    1. maps always store in ascending order...
    2. If the keys are strings then those are stored lexicographically
*/

    map<int, string> m;
    m[1] = "abc";
    m[5] = "cde";
    m[3] = "efg";

    m.insert({6, "ijk"});
    for (auto it = m.begin(); it != m.end(); it++)
    {
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
    cout<<"Size: "<<m.size()<<endl;
    
    //find operation
    auto it = m.find(3);
    if(it == m.end()){
        cout<<"No value"<<endl;
    }else{
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }

    //erase operation
    m.erase(3);
    //clearing the whole map
    m.clear();
}