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
  int totalExtFrag = 0;
  int i = 0;
  while (i < blkv.size()) {
    int proc = tmpv[tmpv.size() - 1];
    if(blkv[i] < proc) {
      i++;
    } else {
      totalExtFrag = totalExtFrag + (blkv[i] - proc);
      blkv[i] = blkv[i] - proc;
      tmpv.pop_back();
    }
  }
  cout<<"For First Fit External Fragmentation: "<<totalExtFrag<<endl;
  

  // best fit
  tmpv.clear();
  tmpv = prcv;
  vector<int> tmpblk = blkv;
  totalExtFrag = 0;
  reverse(tmpv.begin(), tmpv.end());
  sort(tmpblk.begin(), tmpblk.end());

  i = 0;
  while (i < tmpblk.size())
  {
    int proc = tmpv[tmpv.size() - 1];
    if(tmpblk[i] < proc) {
      i++;
    } else {
      tmpblk[i] = tmpblk[i] - proc;
      tmpv.pop_back();
    }
  }
  
  int procLeft = 0;
  for(int val: tmpv) {
    procLeft = procLeft + val;
  }
  int blkLeft = 0;
  for(int val: tmpblk) {
    blkLeft += val;
  }
  if(procLeft > 0) {
    totalExtFrag = blkLeft;
  }
  cout<<"For Best Fit External Fragmentation: "<<totalExtFrag<<endl; 
}