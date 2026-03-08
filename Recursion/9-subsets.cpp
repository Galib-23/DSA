#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& a, vector<int>& cur, int i, vector<vector<int>>& res) {
  if (i == a.size()) {
    res.push_back(cur);
    return;
  }
  // include
  cur.push_back(a[i]);
  dfs(a, cur, i + 1, res);
  // exclude
  cur.pop_back(); // backtrack
  dfs(a, cur, i + 1, res);
}

vector<vector<int>> subsets(vector<int>& a) {
  vector<vector<int>> res;
  vector<int> cur;
  dfs(a, cur, 0, res);
  return res;
}

int main() {
    vector<int> a = {1,2,3};
    auto r = subsets(a);

    for(auto &v : r){
        for(int x : v) cout << x << " ";
        cout << endl;
    }
}