#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(5);
    v.push_back(4);
    v.push_back(2);
    
    //sorting
    cout<<"Sorted elements: "<<endl;
    sort(v.begin(), v.end());
    for(auto i: v){
        cout<<(i)<<" ";
    }cout<<endl;

    //Searching
    cout<<"4 Present or not: "<<binary_search(v.begin(), v.end(), 4)<<endl;

    //Finding the index, lb, and up
    cout<<"Index of 4/ lower Bound: "<<lower_bound(v.begin(), v.end(), 4) - v.begin()<<endl;
    cout<<"Upper Bound: "<<upper_bound(v.begin(), v.end(), 4) - v.begin()<<endl;

    //min | max
    int a = 2;
    int b = 3;
    cout<<"Max is : "<<max(a, b)<<endl;
    cout<<"Min is : "<<min(a, b)<<endl;
    
    swap(a, b);
    cout<<"a = "<<a<<endl<<"b = "<<b<<endl;

    //reverse
    string s = "galib";
    reverse(s.begin(), s.end());
    cout<<s<<endl;

    //rotate
    rotate(v.begin(), v.begin() + 1, v.end());
    cout<<"After Rotation: ";
    for(auto i: v){
        cout<<(i)<<" ";
    }cout<<endl;

}