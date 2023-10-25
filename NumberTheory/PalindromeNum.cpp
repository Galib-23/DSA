#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    vector<int> v;
    while(n){
        int x = n % 10;
        v.push_back(x);
        n/=10;
    }
    int count = 0;
    for (int i = 0, j=v.size()-1; i < v.size(), j>= 0; i++, j--)
    {
        if(v[i] != v[j]){
            count++;
            break;
        }
    }
    if(count) cout<<"Not Palindrome"<<endl;
    else cout<<"Palindrome"<<endl;
    
}
/*
    Another Way: 
    Given n = 125
    1) --> 5
    2) --> 5 * 10 + 2 = 52
    3) --> 52 * 10 + 1 = 521
*/