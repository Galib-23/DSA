// Adjacency List - (O(V+E)) space complexity

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n, m; // Vertext & Edge
  cin>>n>>m; 
  unordered_map<int, vector<int>> graph;

/*

      1
     / \
    2   0

    # List:
    0 -> 1
    1 -> 0, 2
    2 -> 1
*/

  graph[0] = {1};
  graph[1] = {0, 2};
  graph[2] = {1};


  // For weighted Graphs:

  unordered_map<int, vector<pair<int, int>>> wtdGraph;
  int wt;

  wtdGraph[0] = {{1, wt}};
  wtdGraph[1] = {{0, wt}, {2, wt}};
  wtdGraph[2] = {{1, wt}};
  
}