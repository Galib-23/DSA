#include <bits/stdc++.h>

using namespace std;

int main() {
  vector<pair<int, int>> vp;
  sort(vp.begin(), vp.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
    return a.first < b.first;
  });
}