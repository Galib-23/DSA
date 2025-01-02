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
    int cc = 0;
    while (t--)
    {
        // cc++;
        int n, k;
        cin >> n >> k;
        string str;
        cin >> str;
        // if (cc == 45) {
        //     cout << "FKKKK" << endl;
        //     break;
        // }
        string res = "NO";
        if (n - k == 1)
        {
            res = "YES";
        }
        else
        {
            unordered_map<char, int> mp;
            for (int i = 0; i < str.size(); i++)
            {
                if (mp.find(str[i]) == mp.end())
                {
                    mp[str[i]] = 1;
                }
                else
                {
                    mp[str[i]] = mp[str[i]] + 1;
                }
            }
            int oddCount = 0;
            for (auto it = mp.begin(); it != mp.end(); it++)
            {
                if ((*it).second %2 != 0)
                {
                    oddCount++;
                }
            }
            if (oddCount - 1 > k)
            {
                res = "NO";
            } else {
                res = "YES";
            }
        }
        cout<<res<<endl;
    }
}
