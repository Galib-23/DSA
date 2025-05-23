#include<bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cout<<"Enter no. of processes: ";
  cin>>n;
  map<int, pair<int, int>> m;
  vector<int> prv;
  map<int, int> gantt;
  for (int i = 1; i <= n; i++)
  {
    int x, y;
    cout<<"Enter the priority and burst of process "<<i<<" :";
    cin>>x>>y;
    m[i] = {x, y};
    prv.push_back(x);
  }
  sort(prv.begin(), prv.end());
  int totalBurst = 0;
  for(int val: prv) {
    for(const auto&it: m) {
      if(it.second.first == val) {
        totalBurst = totalBurst + it.second.second;
        gantt.insert({it.first, totalBurst});
      }
    }
  }

  int TTT = 0;
  cout<<"Process     "<<"Burst Time        "<<"Priority        "<<"Completion       "<<"Turnaround"<<endl;
  for (int i = 1; i <= n; i++)
  {
    cout<< 'P' << i << "\t\t" << m[i].second << "\t\t" << m[i].first << "\t\t" << gantt[i] << "\t\t" << gantt[i]<< endl;
    TTT = TTT + gantt[i];
  }
  
  cout<<"Average tt: "<<(TTT / n)<<endl;
}