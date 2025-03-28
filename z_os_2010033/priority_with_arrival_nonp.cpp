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
    int process;
    int minArrival = M;
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cout << " Enter arrival, burst and priority of process " << (i) << " : ";
        cin >> x >> y >> z;
        mp[i] = {x, y, z};
        mp2[i] = {x, y, z};
        if (x < minArrival)
        {
            minArrival = x;
            process = i;
        }
        prv.push_back(z);
    }
    int tbt = 0;
    gantt[process] = mp[process][1];
    tbt = tbt + mp[process][1];
    minArrival = tbt;
    for (int i = 0; i < prv.size(); i++)
    {
        if (prv[i] == mp[process][2])
        {
            prv[i] = 500000;
        }
    }
    sort(prv.begin(), prv.end());
    prv.pop_back();
    //reverse(prv.begin(), prv.end());
    mp.erase(process);

    
    while (prv.size() != 0)
    {
        int minPriority = M;
        int minIndex;
        for (const auto &it : mp)
        {
            if (it.second[0] <= minArrival and it.second[2] < minPriority)
            {
                minIndex = it.first;
                minPriority = it.second[2];
            }
        }
        tbt = tbt + mp[minIndex][1];
        minArrival = minArrival + tbt;
        gantt.insert({minIndex, tbt});
        for (int i = 0; i < prv.size(); i++)
        {
            if (prv[i] == mp[minIndex][2])
            {
                prv[i] = 500000;
                break;
            }
        }
        sort(prv.begin(), prv.end());
        prv.pop_back();
        //reverse(prv.begin(), prv.end());
        mp.erase(minIndex);
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
