#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 10e9 + 7;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n, a, b;
        cin >> n >> a >> b;
        int x = 0, y = 0;
        char arr[n];
        bool res = false;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int l = 20;
        while (l--)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 'N')
                {
                    ++y;
                }
                else if (arr[i] == 'E')
                {
                    ++x;
                }
                else if (arr[i] == 'S')
                {
                    --y;
                }
                else if (arr[i] == 'W')
                {
                    --x;
                }
                if (a == x and b == y)
                {
                    res = true;
                    break;
                }
            }
            if (res)
            {
                break;
            }
        }
        if (res)
        {
            cout<<"YES"<<endl;
        } else {
            cout<<"NO"<<endl;
        }
        
    }
}