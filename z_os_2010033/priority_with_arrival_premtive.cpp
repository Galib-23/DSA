#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define int long long
const int M = (3 * 1e9) + 7;

signed main()
{
  cout << "Enter number of processes: ";
  int n;
  cin >> n;
  cout << endl;
  map<int, vector<int>> mp;
  map<int, vector<int>> mp2;
  vector<int> prv;
  map<int, int> gantt;
  int process = 0;
  int minArrival = M;
  int tbt = 0;
  for (int i = 0; i < n; i++)
  {
    int x, y, z;
    cout << " Enter arrival, burst and priority of process " << (i + 1) << " : ";
    cin >> x >> y >> z;
    mp[i + 1] = {x, y, z};
    mp2[i + 1] = {x, y, z};
    tbt = tbt + mp[i + 1][1];
    if (x < minArrival)
    {
      minArrival = x;
      process = i + 1;
    }
  }
  gantt[process] = 1;
  minArrival = minArrival + 1;
  mp[process][1] = mp[process][1] - 1;

  if (mp[process][1] == 0)
  {
    mp.erase(process);
  }

  for (int i = 0; i < tbt; i++)
  {
    if (!mp.empty())
    {
      int minPriority = M;
      int minIndex = -1;
      for (const auto &it : mp)
      {
        if (it.second[0] <= minArrival and it.second[2] <= minPriority)
        {
          minIndex = it.first;
          minPriority = it.second[2];
        }
      }
      minArrival = minArrival + 1;

      if (gantt.find(minIndex) != gantt.end())
      {
        gantt[minIndex] = minArrival;
      }
      else
        gantt.insert({minIndex, minArrival});

      mp[minIndex][1] = mp[minIndex][1] - 1;
      if (mp[minIndex][1] == 0)
      {
        mp.erase(minIndex);
      }
    }
  }

  cout << endl;
  int TTT = 0;
  cout << "Process     " << "Arrival            " << "Burst        " << "Priority          " << "Completion        " << "Turnaround" << endl;
  for (int i = 1; i <= n; i++)
  {
    cout << 'P' << i << "\t\t" << mp2[i][0] << "\t\t" << mp2[i][1] << "\t\t" << mp2[i][2] << "\t\t" << gantt[i] << "\t\t" << gantt[i] - mp2[i][0] << endl;
    TTT = TTT + gantt[i] - mp2[i][0];
  }

  cout << endl;
  cout << "Average Turnaround Time: " << double((double)TTT / n) << endl;
}
