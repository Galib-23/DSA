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
        int a[n];
        char s[n];
        memset(s, '0', n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int ch = 'a';
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                int k = 0;
                for (int j = i; j < n; j++)
                {
                    if (a[j] == k)
                    {
                        if(s[j] == '0'){
                            s[j] = ch;
                            k++;
                        }
                    }
                }
                ch++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}