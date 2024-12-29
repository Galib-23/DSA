#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;


signed main()
{
  int t;
  cout << "Enter number of processes: ";
  cin >> t;
  int n = t;
  cout << endl;
  vector<pair<int, int>> v;
  while (t--)
  {
    int x;
    cout << "Enter the burst time of process " << (n - t) << ": ";
    cin >> x;
    v.push_back(make_pair(n - t, x));
  }
  
  sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b)
       { return a.second < b.second; });
  
  int turnaround = 0;
  int totalTurnaround = 0;
  cout<<endl;
  cout<<"Process"<<"   "<<"Burst"<<"    "<<"Turnaround"<<endl;
  for (int i = 0; i < v.size(); i++){
    turnaround = turnaround + v[i].second;
    totalTurnaround = totalTurnaround + turnaround;
    cout<<"P"<<v[i].first<<"         "<<v[i].second<<"          "<<turnaround<<endl;
  }
  cout<<endl;
  cout<<"Average Turnaround Time: "<<(totalTurnaround/v.size())<<endl;
}