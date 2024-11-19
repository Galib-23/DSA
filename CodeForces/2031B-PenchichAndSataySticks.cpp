#include <bits/stdc++.h>
using namespace std;
#define int long long
const int M = 1e9 + 7;

bool isSorted(int p[], int sorted[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (p[i] != sorted[i])
        {
            return false;
        }
    }
    return true;
}

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
        int p[n];
        int sorted[n];
        bool res = false;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i];
            sorted[i] = p[i];
        }
        sort(sorted, sorted + n);
        res = isSorted(p, sorted, n);
        if (!res)
        {
            int ol = n - 1;
            for (int i = 0; i < n - 1; i++)
            {
                if (abs(p[i] - p[i + 1]) == 1 and (p[i] > p[i + 1]))
                {
                    swap(p[i], p[i + 1]);
                    i++;
                    if (res)
                    {
                        break;
                    }
                }
                else if ((p[i + 1] < p[i]) and abs(p[i] - p[i + 1]) != 1)
                {
                    res = false;
                    break;
                }
            }
            res = isSorted(p, sorted, n);
        }
        if (res)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
