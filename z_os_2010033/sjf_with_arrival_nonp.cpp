#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define int long long
const int M = (3 * 1e9) + 7;

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout << "Enter number of processes: ";
    int n;
    cin >> n;
    cout << endl;
    map<int, pair<int, int>> mp;
    map<int, pair<int, int>> mp2;
    map<int, int> gantt;
    int minArrival = M;
    int process = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << " Enter arrival and burst time of process " << (i + 1) << " : ";
        cin >> x >> y;
        mp[i + 1] = {x, y};
        mp2[i + 1] = {x, y};
        if (x < minArrival)
        {
            minArrival = x;
            process = i + 1;
        }
    }
    gantt.insert({process, mp[process].second});
    minArrival = minArrival + mp[process].second;
    int tbt = mp[process].second;
    mp.erase(process);

    for (int i = 0; i < n - 1; i++)
    {
        int minBurst = M;
        int minIndex = -1;
        for (const auto &it : mp)
        {
            if (it.second.first <= minArrival and it.second.second <= minBurst)
            {
                minBurst = it.second.second;
                minIndex = it.first;
            }
        }
        tbt = tbt + minBurst;
        gantt.insert({minIndex, tbt});
        mp.erase(minIndex);
        minArrival = minArrival + minBurst;
    }
    cout<<endl;
    int TTT = 0;
    cout<<"Process     "<<"Arrival        "<<"Burst Time        "<<"Completion       "<<"Turnaround"<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<< 'P' << i << "\t\t" << mp2[i].first << "\t\t" << mp2[i].second << "\t\t" << gantt[i] << "\t\t" << gantt[i] - mp2[i].first << endl;
        TTT = TTT + gantt[i] - mp2[i].first;
    }
    
    cout<<endl;
    cout<<"Average Turnaround Time: "<< double((double)TTT / n) <<endl;
}
