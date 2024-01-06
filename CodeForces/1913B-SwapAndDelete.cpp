#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int count1 = 0;
        int count0 = 0;
        string t;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                count0++;
            else
                count1++;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
            {
                if (count1 > 0)
                {
                    t += '1';
                    count1--;
                }
                else
                    break;
            }
            else if(s[i] == '1')
            {
                if (count0 > 0)
                {
                    t += '0';
                    count0--;
                }
                else
                    break;
            }
        }
        cout << s.size() - t.size() << endl;
    }
}