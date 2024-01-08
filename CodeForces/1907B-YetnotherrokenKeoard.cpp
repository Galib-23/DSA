#include <bits/stdc++.h>
using namespace std;
bool comparator(int a, int b){
    return a > b;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<int> ust;
        stack<int> lst;
        
        vector<int> u;
        vector<int> l;

        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if(isupper(c) and c != 'B'){
                ust.push(i);
            }else if(islower(c) and c != 'b'){
                lst.push(i);
            }else if(c == 'B' and !ust.empty()){
                u.push_back(ust.top());
                ust.pop();
            }else if(c == 'b' and !lst.empty()){
                l.push_back((lst.top()));
                lst.pop();
            }
        }
        if(u.size()) sort(u.begin(), u.end(), comparator);
        if(l.size()) sort(l.begin(), l.end(), comparator);

        for (int i = 0; i < s.size(); i++)
        {
            if(l.size() and i == l[l.size() - 1]){
                l.pop_back();
            }else if(u.size() and i == u[u.size() - 1]){
                u.pop_back();
            }else if(s[i] != 'b' and s[i] != 'B'){
                cout<<s[i];
            }
        }cout<<endl;
        
        
    }
}