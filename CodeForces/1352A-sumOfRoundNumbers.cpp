#include <bits/stdc++.h>
using namespace std;

int toMultiply(int x)
{
    int y = 1;
    for (int i = 1; i < x; i++)
    {
        y = y * 10;
    }
    return y;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        stack<int> st;
        while (n)
        {
            int rem = n % 10;
            st.push(rem);
            n = n / 10;
        }
        vector<int> v;
        while (!st.empty())
        {
            int tmp = st.top();
            if (st.size() == 1)
            {
                if (tmp != 0)
                    v.push_back(tmp);
            }
            else
            {
                int toM = toMultiply(st.size());
                if (tmp * toM != 0)
                    v.push_back(tmp * toM);
            }
            st.pop();
        }

        cout << v.size() << endl;
        for (int i = 0; i < v.size(); i++)
        {
            // if(v[i] != 0){
            cout << v[i] << " ";
            //  }
        }
        cout << endl;
    }
}