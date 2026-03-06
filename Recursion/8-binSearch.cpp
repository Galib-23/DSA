#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> arr, int k, int l, int r) {
  if(l <= r) {
    int mid = (l + r) / 2;
    if(arr[mid] == k) {
      return mid;
    }
    else if(k < arr[mid]) {
      return binarySearch(arr, k, l, mid - 1);
    } else{
      return binarySearch(arr, k, mid + 1, r);
    }
  }
  return -1;
}

int main() {
  vector<int> arr = {1, 2, 2, 2, 8};
  int idxOfK = binarySearch(arr, 8, 0, arr.size() - 1);
  cout<<idxOfK<<endl;
  return 0;
}