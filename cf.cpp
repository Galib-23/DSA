#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = (3 * 1e9) + 7;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<vector<int>> v(n, vector<int>(n));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cin>>v[i][j];
            }
        }
        bool c2 = true;
        bool c3 = true;
        for(int i = 0; i < n; i++) {
            int hc = 0;
            for(int j = 0; j < n; j++) {
                if(v[i][j] == '#') {
                    hc++;
                    if(hc >= 3) {
                        c3 = false;
                        break;
                    }
                } else {
                    hc = 0;
                }
            }
        }
        for(int i = 0; i < n; i++) {
            int hc = 0;
            for(int j = 0; j < n; j++) {
                if(v[j][i] == '#') {
                    hc++;
                    if(hc >= 3) {
                        c3 = false;
                        break;
                    }
                } else {
                    hc = 0;
                }
            }
        }
        if(c3) {
            
        }


        if(c3 and c2) {
            cout<<"YES"<<endl;
        } else cout<<"NO"<<endl;
    }
}
