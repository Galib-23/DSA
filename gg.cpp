#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int count = 0;
   vector<pair<int, int>> v;
   for (int i = 0; i < n; i++)
   {
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a, b));
   }
   for (int i = 0; i < n; i++)
   {
        int a = v[i].first;
        int b = v[i].second;
        for (int j = 0; j < n; j++)
        {
            if(i == j) continue;;
            if(v[j].first == b){
                count++;
            }
            if(v[j].second == a) count++;
        }
   }
   cout<<count/2<<endl;
   
}