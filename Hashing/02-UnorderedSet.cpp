#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_set<int> s;
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