#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;
        unordered_map<int, vector<int>> m;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            int rem = x % k;
            if (rem < 0) rem += k; // Ensure positive remainder

            m[rem].push_back(i);
        }

        for (int i = 0; i < k; i++) {
            for (int j : m[i]) {
                cout << j << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
