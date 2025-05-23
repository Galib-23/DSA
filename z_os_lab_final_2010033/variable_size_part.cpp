#include<bits/stdc++.h>
using namespace std;
struct Fragmentation {
  int internal;
  int external;
};
Fragmentation allocProc(vector<int>& tmpv, vector<pair<int, int>> tmpBlocks) {
  int totalUnallocProc = 0;
  while (!tmpv.empty()) {
    int proc = tmpv[tmpv.size() - 1];
    bool flag = false;
    for(auto& it: tmpBlocks) {
      if(it.first >= proc) {
        it.first = it.first - proc;
        flag = true;
        break;
      }
    }
    if(!flag) {
      totalUnallocProc += proc;
    }
    tmpv.pop_back();
  }
  // Internal Fragmentation
  int totalInt = 0;

  // External Fragmentation
  int totalAvailable = 0;
  if(totalUnallocProc > 0) {
    for(const auto& it: tmpBlocks) {
       totalAvailable += it.first;
    }
  }
  int totalExt = 0;
  if(totalAvailable > totalUnallocProc) {
    totalExt = totalUnallocProc;
  }

  Fragmentation result;
  result.internal = totalInt;
  result.external = totalExt;
  return result;
}

int main() {
  int b, p;
  cout<<"Enter the num of blocks: ";
  cin>>b;
  cout<<"Enter the num of processes: ";
  cin>>p;

  vector<pair<int, int>> blocks;
  cout<<"Enter the size of the blocks: "<<endl;
  for (int i = 1; i <= b; i++) {
    int x;
    cout<<"Block "<<i<<" : ";
    cin>>x;
    blocks.push_back({x, x});
  }
  
  vector<int> pv;
  cout<<"Enter the size of the processes: "<<endl;
  for (int i = 0; i < p; i++) {
    int x;
    cout<<"Process "<<i<<" : ";
    cin>>x;
    pv.push_back(x);
  }
  reverse(pv.begin(), pv.end());

 //------FIRST FIT-------
 vector<int> tmpv = pv;
 vector<pair<int, int>> tmpBlocks = blocks;
 Fragmentation firstFrag = allocProc(tmpv, tmpBlocks);
 cout<<"For Best Fit"<<endl;
 cout<<"Internal Frag: "<<firstFrag.internal<<endl;
 cout<<"External Frag: "<<firstFrag.external<<endl<<endl;

 //------BEST FIT--------
 tmpv = pv;
 tmpBlocks = blocks;

 sort(tmpBlocks.begin(), tmpBlocks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
   return a.second < b.second;
 });
 Fragmentation bestFrag = allocProc(tmpv, tmpBlocks);
 cout<<"For Best Fit: " << endl;
 cout<<"Internal Frag: "<<bestFrag.internal<<endl;
 cout<<"External Frag: "<<bestFrag.external<<endl<<endl;

 //------WORST FIT--------
 tmpv = pv;
 tmpBlocks = blocks;
 sort(tmpBlocks.begin(), tmpBlocks.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
   return a.second > b.second; 
 });
 Fragmentation worstFrag = allocProc(tmpv, tmpBlocks);
 cout<<"For Worst Fit: " << endl;
 cout<<"Internal Frag: "<<worstFrag.internal<<endl;
 cout<<"External Frag: "<<worstFrag.external<<endl;

}
   