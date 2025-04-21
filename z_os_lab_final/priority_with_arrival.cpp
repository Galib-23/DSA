#include<bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cout<< "Enter the no. of processes: ";
  cin>>n;
  map<int, vector<int>> m;
  int minArrival = 1000;
  vector<int> prv;
  for (int i = 1; i <= n; i++)
  {
    int x, y, z;
    cout<<"Enter the priority, arrival & burst of process "<<i<<" : ";
    cin>>x>>y>>z;
    m[i] = {x, y, z};
    if(y < minArrival) minArrival = y;
  }
  
}