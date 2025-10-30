#include <bits/stdc++.h>
using namespace std;

// in 0 based indexing
//parent = (i - 1) / 2;
// childs ate 2i + 1 and 2i + 2

void heapify(vector<int> &v, int n, int i)
{
    int largest = i;
    if(2*i + 1 < n and v[largest] < v[2*i + 1]) {
      largest = 2*i + 1;
    }
    if(2*i + 2 < n and v[largest] < v[2*i + 2]) largest = 2*i + 2;
    if (largest != i) {
      swap(v[largest], v[i]);
      heapify(v, n, largest);
    }
}

void heapSort(vector<int> &v) {
  int n = v.size(); 
  for(int i = (n/2) - 1; i >= 0; i--) {
    heapify(v, n, i);
  }
  for(int i = n - 1; i > 0; i--) {
    swap(v[0], v[i]);
    heapify(v, i, 0);
  }
}

int main()
{
  vector<int> v = {10, 20, 15, 30, 40};
  int r = v.size() - 1;
  heapSort(v);
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}