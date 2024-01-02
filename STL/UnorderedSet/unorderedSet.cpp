#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    if(s.find(5) == s.end()) //s.find returns an iterator. So if the iterator has reached the end that means it's not found
    {
        cout<<"Not found"<<endl; 
    }
    else cout<<"Found"<<endl;

    //iteration
    for(auto it = s.begin(); it != s.end(); it++){
        cout<<(*it)<<" ";
    }

    s.clear();
    cout<<s.size()<<endl;

    s.insert(1);
    s.insert(5);
    s.insert(3);
    s.insert(5);
    cout<<"Number of 5 persent: "<<s.count(5)<<endl; //basically in u_s count always  = 1
    //so we can check if any number is present here or not
    s.erase(5);
    if(s.count(5) == 0){
        cout<<"Not present"<<endl;
    }
}