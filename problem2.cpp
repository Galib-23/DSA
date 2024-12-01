#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;

int processNo(map<int, int> m, int arrival) {
  for (auto it = m.begin(); it != m.end(); it++)
    {
        if ((*it).second == arrival)
        {
          return (*it).first;
        }
        
    }
    cout<<"Size: "<<m.size()<<endl;
}

signed main()
{
    int t;
    cout<<"Enter number of processes: ";
    cin>>t;
    int n = t;
    cout<<endl;
    vector<pair<int, int>> v;
    vector<int> sortedp;
    map<int, int> p;
    while (t--)
    {
        int x;
        int y;
        cout<<"Enter the burst time and arrival time of process "<<(n - t - 1)<<": ";
        cin>>x;
        cin>>y;
        p[n - t - 1] = x;
        v.push_back(make_pair(x, y));
    }
     sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    });
    for (int i = 0; i < v.size(); i++)
    {
      int x = processNo(p, v[i].first);
      sortedp.push_back(x);
    }
    int waiting = 0;
    int turnaround = v[0].first;
    int completion = 0;
    cout<<"Process"<<" "<<"Arrival"<< " Burst"<<" Turnaround"<<" Waiting"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
      turnaround = waiting + v[i].second;
      completion = completion + v[i].second;
      cout<<sortedp[i]<<" "<<v[i].first<<" "<<v[i].second<<" "<<turnaround<<" "<<waiting<<endl;
      waiting = completion - v[i].first;
    }
    
}