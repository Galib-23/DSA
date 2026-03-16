#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
  Node* dfs(vector<vector<int>>& grid, int n, int r, int c) {
    bool isL = true;
    int x = grid[r][c];
    int nr = r + n;
    int nc = c + n;
    for(int i = r; i < nr; i++) {
      for(int j = c; j < nc; j++) {
        if(grid[i][j] != x) {
          isL = false;
          break;
        }
      }
      if(!isL) break;
    }
    if(isL && x == 1) return new Node(true, true); 
    else if(isL && x == 0) return new Node(false, true);
    else{
      Node* newNode = new Node(false, false);
      newNode->topLeft = dfs(grid, n/2, r, c);
      newNode->topRight = dfs(grid, n/2, r, (c + n/2) - 1);
      newNode->bottomLeft = dfs(grid, n/2, (r + n/2) - 1, c);
      newNode->bottomRight = dfs(grid, n/2, (r + n/2) - 1, (c + n/2) - 1);
      return newNode;
    }
  }
  Node* construct(vector<vector<int>>& grid) {
    int n = grid.size();
    Node* root = dfs(grid, n, 0, 0);
    return root;
  }
};
int main() {

}