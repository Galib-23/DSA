#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    //if size is known: 
    vector<int> v2(5, 1);//all initialized with 1
    //copying v2 in v3
    vector<int> v3(v2);

    cout<<"Capacity: "<<v.capacity()<<endl;
    
    v.push_back(1);
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(2);
    cout<<"Capacity: "<<v.capacity()<<endl;

    v.push_back(3);
    cout<<"Capacity: "<<v.capacity()<<endl;
    cout<<"Size: "<<v.size()<<endl;

    cout<<"Element at 2nd index: "<<v.at(2)<<endl;
    cout<<"Front: "<<v.front()<<endl;
    cout<<"Back: "<<v.back()<<endl;

    cout<<"Before Pop: "<<endl;
    for(int i: v){
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();

    cout<<"After Pop: "<<endl;
    for(int i: v){
        cout<<i<<" ";
    }cout<<endl;

    //Clearing a vector: 
    v.clear();
}