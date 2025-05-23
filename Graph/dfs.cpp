#include<bits/stdc++.h>
using namespace std;

void dfs(int vertex, unordered_map<int, vector<int>> &graph,  vector<bool> &visited) {
  visited[vertex] = true;
  
  cout<<vertex<<endl; // print dfs order
  
  for(int child: graph[vertex]) {
    if(visited[child]) continue;
    dfs(child, graph, visited);
  }
}

int main() {
  int n, m;
  cin>>n>>m;

  // adjacency list
  unordered_map<int, vector<int>> graph;
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  // DFS
  vector<bool> visited(n, false);
  dfs(1, graph, visited);
}