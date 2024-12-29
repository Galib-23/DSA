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
        int n, m;
        cin >> n >> m;
        vector<int> v;
        vector<int> vres;
        int maxi = 0;
        for (int i = 0; i < n; i++){
            int x;
            cin>>x;
            if (x > maxi)
            {
                maxi = x;
            }
            v.push_back(x);
        }
        for (int i = 0; i < m; i++){
            char c;
            int l;
            int r;
            cin >>c >> l >> r;
            if (c == '+'){
                if (maxi >= l and maxi <= r){
                    maxi = maxi + 1;
                    vres.push_back(maxi);
                } else {
                    vres.push_back(maxi);
                }
            } else {
                if (maxi >= l and maxi <= r){
                    maxi = maxi - 1;
                    vres.push_back(maxi);
                } else {
                    vres.push_back(maxi);
                }
            }
        }
        for (int i = 0; i < vres.size(); i++)
        {
            cout<<vres[i]<< " ";
        }
        cout<<endl;
    }
}
