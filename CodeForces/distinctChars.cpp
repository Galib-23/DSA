#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin>>str;
    unordered_set<char> s; //in unordered set only distinct elements are stored
    for (int i = 0; i < str.size(); i++)
    {
        s.insert(str[i]);
    }
    int len = s.size();
    if(len % 2 == 0){
        cout<<"CHAT WITH HER!"<<endl;
    }
    else{
        cout<<"IGNORE HIM!"<<endl;
    }
    
}