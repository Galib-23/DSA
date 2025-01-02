#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--){
        int a, b;
        cin >> a >> b;
        int xk, yk, xq, yq;
        cin >> xk >> yk;
        cin >> xq >> yq;
        vector<pair<int, int>> vk;
        vector<pair<int, int>> vq;

        // King
        vk.push_back({(xk - b), (yk + a)});
        vk.push_back({(xk - b), (yk - a)});
        vk.push_back({(xk + b), (yk + a)});
        vk.push_back({(xk + b), (yk - a)});
        vk.push_back({(xk + a), (yk - b)});
        vk.push_back({(xk - a), (yk - b)});
        vk.push_back({(xk + a), (yk + b)});
        vk.push_back({(xk - a), (yk + b)});

        //Queen
        vq.push_back({(xq - b), (yq + a)});
        vq.push_back({(xq - b), (yq - a)});
        vq.push_back({(xq + b), (yq + a)});
        vq.push_back({(xq + b), (yq - a)});
        vq.push_back({(xq + a), (yq - b)});
        vq.push_back({(xq - a), (yq - b)});
        vq.push_back({(xq + a), (yq + b)});
        vq.push_back({(xq - a), (yq + b)});

        int count = 0;

        for (int i = 0; i < vq.size(); i++)
        {
          for (int j = 0; j < vk.size(); j++)
          {
            if (vq[i].first == vk[j].first and vq[i].second == vk[j].second)
            {
              count++;
            }
          }
        }
        if (a == b)
        {
          cout<< log2(count) - 1 << endl;
        } else {
          cout<< count << endl;
        }
        
    }
}
