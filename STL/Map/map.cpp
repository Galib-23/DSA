#include<bits/stdc++.h>
using namespace std;
int main(){

/*
    1. maps always store in ascending order...
    2. If the keys are strings then those are stored lexicographically

    # Unordered Map all same as normal map just it doesnt store keys in a sorted manner
      and the time complexity for all cases is either O(1) / log(1)
*/

    map<int, string> m;
    m[1] = "abc"; // insertion time log(n) if key is string insert time = s.size()*log(n)
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