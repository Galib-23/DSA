#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  int n;
  cout << "Enter the no. of processes: ";
  cin >> n;
  int xt, yt, zt;
  cout << "Enter the total no. of resources for A B C: ";
  cin >> xt >> yt >> zt;
  map<int, pair<vector<int>, vector<int>>> mp;
  int ta = 0, tb = 0, tc = 0;
  set<int> sc;
  for (int i = 1; i <= n; i++)
  {
    int a, b, c;
    cout << "Enter Allocation for process " << i << " : ";
    cin >> a >> b >> c;
    ta += a;
    tb += b;
    tc += c;
    int x, y, z;
    cout << "Enter max for process " << i << " : ";
    cin >> x >> y >> z;
    mp[i] = {{a, b, c}, {x, y, z}};
    sc.insert(i);
  }

  int aa = xt - ta;
  int ba = yt - tb;
  int ca = zt - tc;

  vector<vector<int>> vNeed;
  vNeed[0] = {-1, -1, -1};
  for (int i = 1; i <= n; i++)
  {
    int o, p, q;
    o = mp[i].second[0] - mp[i].first[0];
    p = mp[i].second[1] - mp[i].first[1];
    q = mp[i].second[2] - mp[i].first[2];
    vNeed[1] = {o, p, q};
  }
  
  cout<<"Need Matrix: "<<endl;
  for (int i = 1; i <= n ; i++)
  {
    cout<<i<<": "<<vNeed[i][0]<<" "<<vNeed[i][1]<<" "<<vNeed[i][2];
  }
  
  int res = 1;

  while (!sc.empty())
  {
    bool flag = true;
    int mapIndex;
    for (const auto &it : mp)
    {
      if (vNeed[it.first][0] <= aa && vNeed[it.first][1] <= ba && vNeed[it.first][2] <= ca)
      {
        aa = aa + it.second.first[0];
        ba = ba + it.second.first[1];
        ca = ca + it.second.first[2];
        mp.erase(it.first);
        mapIndex = it.first;
        flag = false;
        break;
      }
    }
    if (flag == true)
    {
      res = 0;
      break;
    }
    sc.erase(mapIndex);
  }
  if (res == 1)
  {
    cout<<"Safe sequence exist!"<<endl;
  } else cout<<"Safe seq not present"<<endl;
  
}
