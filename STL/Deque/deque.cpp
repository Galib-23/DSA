#include<bits/stdc++.h>
using namespace std;
int main(){
    deque<int> d;

    d.push_back(1);
    d.push_front(2);
    d.push_back(3);
    d.push_back(4);
    d.push_front(5);

    for (int i: d)
    {
        cout<<i<<endl;
    }

    d.pop_back();
    d.pop_front();

    cout<<"Print first element: "<<d.at(1)<<endl;
    cout<<"Front: "<<d.front()<<endl;
    cout<<"Back: "<<d.back()<<endl;

    cout<<"Empty or not: "<<d.empty()<<endl;
    cout<<"Size: "<<d.size()<<endl;
    //erase
    d.erase(d.begin(), d.begin() + 2); // erases first two elements
    
}