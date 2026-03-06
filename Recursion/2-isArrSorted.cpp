#include <bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr, int n) {
  if(n == 0) return true;
  bool is = isSorted(arr, n - 1);
  if(!is) return false;
  if(n + 1 < arr.size()) return arr[n] <= arr[n + 1];
  else return true;
}

int main() {
  vector<int> arr = {1, 2, 2, 2, 8};
  bool sorted = isSorted(arr, arr.size() - 1);
  cout<<sorted<<endl;
  return 0;
}