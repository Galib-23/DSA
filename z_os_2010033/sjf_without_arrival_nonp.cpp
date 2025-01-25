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
    cout<< "Enter number of processes: ";
    int n;
    cin>>n;
    cout<<endl;
    vector<pair<int, int>> v;
    vector<pair<int, int>> vt;
    for (int i = 0; i < n; i++)
    {
        int x;
        cout<<" Enter the burst time of process "<<(i+1)<<" : ";
        cin>>x;
        v.push_back({i+1, x});
        vt.push_back({i+1, x});
    }
    sort(v.begin(), v.end(), [](const pair<int, int>& p1, const pair<int, int>& p2){
        return p1.second < p2.second;
    });
    
    map<int, int> mp;
    int CT = 0;
    for (int i = 0; i < n; i++)
    {
        CT = CT + v[i].second;
        mp[v[i].first] = CT;
    }
    cout<<endl;
    int TTT = 0;
    cout<<"Process     "<<"Burst Time      "<<"Completion      "<<"Turnaround"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<< 'P' << vt[i].first<< "\t\t" << vt[i].second << "\t\t" << mp[i+1] << "\t\t" << mp[i+1] << endl;
        TTT = TTT + mp[i + 1];
    }
    cout<<endl;
    cout<<"Average Turnaround Time: "<< double((double)TTT / n) <<endl;
}
