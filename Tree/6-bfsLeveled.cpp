#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> res;
      queue<TreeNode*> q;
      q.push(nullptr);
      int i = 0;
      if(root != nullptr) q.push(root);
      else return res;
      q.push(nullptr);
      while(!q.empty()) {
        vector<int> tmp;
        q.pop();
        while(q.front() != nullptr) {
          if(q.front()->left != nullptr) q.push(q.front()->left);
          if(q.front()->right != nullptr) q.push(q.front()->right);
          tmp.push_back(q.front()->val);
          q.pop();
        }
        q.pop();
        q.push(nullptr);
        res.push_back(tmp);
        tmp.clear();
      }
      return res;
    }
};

int main() {

}