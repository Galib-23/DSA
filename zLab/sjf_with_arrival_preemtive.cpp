#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;

struct Process {
  int processNo;
  int arrival;
  int burst;
  int turnaround;
};

int findProcess(vector<Process> v, int j  ){

  for (int i = j; i < v.size(); i++){
    
  }
  
}

signed main()
{
  int t;
  cout << "Enter number of processes: ";
  cin >> t;
  int n = t;
  cout << endl;
  vector<Process> v;
  map<int, int> gantt;
  int mini = M;
  while (t--)
  {
    Process p;
    int x, y;
    cout << "Enter the arrival & burst time of process " << (n - t) << ": ";
    cin >> x;
    cin >> y;
    p.processNo = n - t;
    p.arrival = x;
    p.burst = y;
    p.turnaround = 0;
    v.push_back(p);
  }
  
  
  int turnaround = 0;
  int totalTurnaround = 0;
  cout<<endl;
  cout<<"Process"<<" "<<"Burst"<<" "<<"Turnaround"<<endl;
  for (int i = 0; i < v.size(); i++){
    turnaround = turnaround + v[i].second;
    totalTurnaround = totalTurnaround + turnaround;
    cout<<"P"<<v[i].first<<"         "<<v[i].second<<"      "<<turnaround<<"      "<<endl;
  }
  cout<<endl;
  cout<<"Average Turnaround Time: "<<(totalTurnaround/v.size())<<endl;
}