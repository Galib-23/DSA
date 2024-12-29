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
        int n;
        cin >> n;
        string temp = "aeiou";
        if (n <= 5){
          for (int i = 0; i < n; i++){
            cout<<temp[i];
          } cout<<endl;
        } else {
          int base = n / 5;
          int left = n % 5;
          string res = "";
          for (int i = 0; i < 5; i++)
          {
            for (int j = 0; j < base; j++){
              res += temp[i];
            }

            if (left == 1 and temp[i] == 'i'){
              res += temp[i];
            }
            else if (left == 2 and (temp[i] == 'i' || temp[i] == 'e')){
              res += temp[i];
            }
            else if (left == 3 and (temp[i] == 'i' || temp[i] == 'e' || temp[i] == 'o')){
              res += temp[i];
            }
            else if (left == 4 and (temp[i] == 'i' || temp[i] == 'e' || temp[i] == 'o' || temp[i] == 'a')){
              res += temp[i];
            }
          }
          cout<<res<<endl;
        }
        
        
    }
}
