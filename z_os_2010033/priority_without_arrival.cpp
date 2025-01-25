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
    map<int, pair<int, int>> mp;
    vector<int> prv;
    map<int, int> gantt;
    int minPriority = M;
    int process = 0;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cout << " Enter burst and priority of process " << (i + 1) << " : ";
        cin >> x >> y;

        mp[i + 1] = {x, y};
        prv.push_back(y);
    }
    int tbt = 0;
    sort(prv.begin(), prv.end());
    reverse(prv.begin(), prv.end());

    for (int i = n - 1; i >=0; i--)
    {
        int minIndex = -1;
        for (const auto &it : mp)
        {
            if (it.second.second == prv[i])
            {
                minIndex = it.first;
                prv.pop_back();
                break;
            }
        }
        tbt = tbt + mp[minIndex].first;
        gantt.insert({minIndex, tbt});
    }
    cout<<endl;
    int TTT = 0;
    cout<<"Process     "<<"Burst Time        "<<"Arrival        "<<"Completion       "<<"Turnaround"<<endl;
    for (int i = 1; i <= n; i++)
    {
        cout<< 'P' << i << "\t\t" << mp[i].first << "\t\t" << mp[i].second << "\t\t" << gantt[i] << "\t\t" << gantt[i] - mp[i].first << endl;
        TTT = TTT + gantt[i] - mp[i].first;
    }
    
    cout<<endl;
    cout<<"Average Turnaround Time: "<< double((double)TTT / n) <<endl;
}
