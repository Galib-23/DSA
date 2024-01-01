#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<string> s;

    s.push("abc");
    s.push("def");
    s.push("ghi");
    s.push("jkl");

    cout<<"top element: "<<s.top()<<endl;
    int n = s.size();
    for (int i = 0; i < n; i++)
    {
        cout<<s.top()<<endl;
        s.pop();
    }
    cout<<"Empty or not: "<<s.empty()<<endl;
    
}