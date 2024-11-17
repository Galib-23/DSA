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
        int n;
        cin >> n;
        int a[n][n];
        vector<vector<int>> v;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int total = 0;
        for (int j = 0; j < n; j++)
        {
            int mini = M;
            int b = 0;
            int c = j;
            for (int k = 0; k < n - j; k++)
            {
                if (a[b][c] < mini)
                {
                    mini = a[b][c];
                }
                b++;
                c++;
            }
            if (mini < 0)
            {
                total = total - mini;
            }
        }
        for (int i = 1; i < n; i++)
        {
            int mini = M;
            int b = i;
            int c = 0;
            for (int k = 0; k < n - i; k++)
            {
                if (a[b][c] < mini)
                {
                    mini = a[b][c];
                }
                b++;
                c++;
            }
            if (mini < 0)
            {
                total = total - mini;
            }
        }
        cout<<total<<endl;
    }
}