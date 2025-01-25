#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
#define int long long
const int M = (3 * 1e9) + 7;

int findShortestJob(map<int, pair<int, int>> mp)
{
}

signed main()
{
    cout << "Enter number of processes: ";
    int n;
    cin >> n;
    cout << endl;
    map<int, pair<int, int>> mp;
    map<int, pair<int, int>> mp2;
    map<int, int> gantt;
    int minArrival = M;
    int process = 0;
    int tbt = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << " Enter arrival and burst time of process " << (i + 1) << " : ";
        cin >> x >> y;
        mp[i + 1] = {x, y};
        mp2[i + 1] = {x, y};
        tbt = tbt + y;
        if (x < minArrival)
        {
            minArrival = x;
            process = i + 1;
        }
    }
    gantt.insert({process, 1});
    minArrival = minArrival + 1;
    mp[process].second = mp[process].second - 1;

    if (mp[process].second == 0)
    {
        mp.erase(process);
    }
    for (int i = 0; i < tbt; i++)
    {
        if (!mp.empty())
        {
            int minBurst = M;
            int minIndex = -1;
            for (const auto &it : mp)
            {
                if (it.second.first <= minArrival and it.second.second < minBurst)
                {
                    minBurst = it.second.second;
                    minIndex = it.first;
                }
            }
            minArrival = minArrival + 1;
            if (gantt.find(minIndex) != gantt.end())
            {
                gantt[minIndex] = minArrival;
            }
            else
                gantt.insert({minIndex, minArrival});

            mp[minIndex].second = mp[minIndex].second - 1;
            if (mp[minIndex].second == 0)
            {
                mp.erase(minIndex);
            }
        }
    }
    cout << endl;
    int TTT = 0;
    cout << "Process     " << "Arrival        " << "Burst Time        " << "Completion       " << "Turnaround" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << 'P' << i << "\t\t" << mp2[i].first << "\t\t" << mp2[i].second << "\t\t" << gantt[i] << "\t\t" << gantt[i] - mp2[i].first << endl;
        TTT = TTT + gantt[i] - mp2[i].first;
    }

    cout << endl;
    cout << "Average Turnaround Time: " << double((double)TTT / n) << endl;
}
