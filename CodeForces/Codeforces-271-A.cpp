#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int ct = 0;
    for (int i = n + 1; i <= 10000; i++)
    {
        unordered_set<int> s;
        int temp = i;
        while (temp)
        {
            int rem = temp % 10;
            s.insert(rem);
            temp = temp / 10;
            if (s.size() == 4)
            {
                cout << i << endl;
                ct++;
                break;
            }
        }
        s.clear();
        if(ct) break;
    }
}