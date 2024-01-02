#include<bits/stdc++.h>
using namespace std;
int main(){
    set<int> s;
    
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(2);
    s.insert(1);
    s.insert(3);

    for(auto i: s){
        cout<<i<<" ";
    }cout<<endl;

    set<int>::iterator it = s.begin();
    s.erase(it); //deletes first element
    
    //Present or not
    cout<<"3 present or not: "<<s.count(3)<<endl;
   
    //Other Functions: 
        //find()
        //delete()
}