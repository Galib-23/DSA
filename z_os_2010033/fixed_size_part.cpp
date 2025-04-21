#include<bits/stdc++.h>
using namespace std;

int main() {
  int blocks;
  int processes;
  vector<int> blkv;
  vector<int> prcv;

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
    blkv.push_back(tmp);
  }

  cout<<"Enter the size of the processes: "<<endl;
  for (int i = 1; i <= processes; i++){
    int tmp;
    cout<<"Process "<<i<<": ";
    cin>>tmp;
    prcv.push_back(tmp);
  }

  // first fit
  vector<int> tmpv = prcv;
  reverse(tmpv.begin(), tmpv.end());
  int totalIntFrag = 0;
  for(int i = 0; i < blkv.size(); i++) {
    int proc = tmpv[tmpv.size() - 1];
    if(blkv[i] < proc) {
      continue;
    } else {
      totalIntFrag = totalIntFrag + (blkv[i] - proc);
      tmpv.pop_back();
    }
  }
  cout<<"For First Fit Internal Fragmentation: "<<totalIntFrag<<endl;
  
  
  //best Fit

  tmpv.clear();
  tmpv = prcv;
  vector<int> tmpblk = blkv;
  totalIntFrag = 0;
  reverse(tmpv.begin(), tmpv.end());
  for (int i = 0; i < processes; i++){
    sort(tmpblk.begin(), tmpblk.end());
    int j = 0;
    while (j < tmpblk.size() and tmpblk[j] < 0) {
     j++;
    }
    if(j < tmpblk.size()) {
      totalIntFrag = totalIntFrag + (tmpblk[j] - tmpv[tmpv.size() - 1]);
      tmpblk[j] = -1;
      tmpv.pop_back();
    }
  }
  cout<<"For Best Fit Internal Fragmentation: "<<totalIntFrag<<endl;

  // worst fit
  tmpv.clear();
  tmpv = prcv;
  tmpblk = blkv;
  totalIntFrag = 0;
  reverse(tmpv.begin(), tmpv.end());
  for (int i = 0; i < processes; i++){
    sort(tmpblk.begin(), tmpblk.end());
    int j = tmpblk.size() - 1;
    if(j > 0) {
      totalIntFrag = totalIntFrag + (tmpblk[j] - tmpv[tmpv.size() - 1]);
      tmpblk[j] = -1;
      tmpv.pop_back();
    }
  }
  cout<<"For Worst Fit Internal Fragmentation: "<<totalIntFrag<<endl;
  
}