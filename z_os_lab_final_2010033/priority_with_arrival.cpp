#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cout << "Enter the no. of processes: ";
  cin >> n;
  int minArrival = 1000;
  map<int, vector<int>> m;
  map<int, vector<int>> m2;
  map<int, int> gantt;
  vector<int> prv;
  for (int i = 1; i <= n; i++)
  {
    int x, y, z;
    cout << "Enter the priority, arrival & burst of process " << i << " : ";
    cin >> x >> y >> z;
    m[i] = {x, y, z};
    m2[i] = {x, y, z};
    if (y < minArrival)
      minArrival = y;
    prv.push_back(x);
  }
  sort(prv.begin(), prv.end());

  while (!m.empty()){
    vector<int> minProc;
    for (const auto &it : m){
      if (it.second[1] <= minArrival){
        minProc.push_back(it.first);
      }
    }
    int minPriority = 1000;
    int exeProc;
    for (int proc: minProc){
      if(m[proc][0] < minPriority) {
        minPriority = m[proc][0];
        exeProc  = proc;
      } else if (m[proc][0] == minPriority) {
        if(m[exeProc][1] > m[proc][1]) {
          exeProc = proc;
        }
      }
    }
    minArrival = minArrival + m[exeProc][2];
    gantt[exeProc] = minArrival;
    minProc.clear();
    m.erase(exeProc);
  }
  
  cout << endl;
  int TTT = 0;
  cout << "Process     " << "Priority            " << "Arrival        " << "Burst          " << "Completion        " << "Turnaround" << endl;
  for (int i = 1; i <= n; i++) {
    cout << 'P' << i << "\t\t" << m2[i][0] << "\t\t" << m2[i][1] << "\t\t" << m2[i][2] << "\t\t" << gantt[i] << "\t\t" << gantt[i] - m2[i][1] << endl;
    TTT = TTT + gantt[i] - m2[i][1];
  }
  cout << endl;
  cout << "Average Turnaround Time: " << double((double)TTT / n) << endl;
}