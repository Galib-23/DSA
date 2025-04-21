#include<bits/stdc++.h>
using namespace std;

int main() {
  int blocks;
  int processes;
  vector<pair<int, int>> blkv;
  vector<pair<int, int>> prcv;

  cout<<"Enter the number of blocks: ";
  cin>>blocks;
  cout<<"Enter the number of processes: ";
  cin>>processes;
  cout<<endl;

  cout<<"Enter the size of the blocks (fixed size): "<<endl;
  for (int i = 1; i <= blocks; i++){
    int tmp;
    cout<<"Block "<<i<<": ";
    cin>>tmp;
    blkv.push_back({i, tmp});
  }

  cout<<"Enter the size of the processes: "<<endl;
  for (int i = 1; i <= processes; i++){
    int tmp;
    cout<<"Process "<<i<<": ";
    cin>>tmp;
    prcv.push_back({i, tmp});
  }

  // For first fit
  vector<pair<int, int>> tmpv = prcv;
  reverse(tmpv.begin(), tmpv.end());
  int totalIntFrag = 0;
  for(int i = 0; i < blkv.size(); i++) {
    int proc = tmpv[tmpv.size() - 1].second;
    if(blkv[i].second < proc) {
      continue;
    } else {
      totalIntFrag = totalIntFrag + (blkv[i].second - proc);
      tmpv.pop_back();
    }
  }
  cout<<totalIntFrag<<endl;
  
  // For Best Fit
  
}