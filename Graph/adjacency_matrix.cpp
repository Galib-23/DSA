// Adjacency Matrix (O(N^2)) space complexity

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m; // Vertext & Edge
  cin>>n>>m; 
  vector<vector<int>> graph(n, vector<int>(n, 0)); // all init with 0

  // all connected vertex = 1
  for (int i = 0; i < n; i++)
  {
    int vtx1, vtx2;
    cin>>vtx1>>vtx2;
    graph[vtx1][vtx2] = 1;
    graph[vtx2][vtx1] = 1;

    // For weighted graphs
    /*
      graph[vtx1][vtx2] = wt;
    */
  }
  
}