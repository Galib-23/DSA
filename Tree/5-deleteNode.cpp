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
  TreeNode* findMin(TreeNode* root) { // minimum of the right subtree
    if(root == nullptr) return nullptr;
    if(root->left == nullptr) return root;
    return findMin(root->left);
  }
  TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == nullptr) return root;
    if(key < root->val) root->left = deleteNode(root->left, key);
    if(key > root->val) root->right = deleteNode(root->right, key);
    else{
      // no child
      if(root->right == nullptr and root->left == nullptr) {
        delete root;
        return nullptr;
      } else if(root->right == nullptr) {
        TreeNode *temp = root;
        root = root->left;
        delete temp;
        return root;
      } else if(root->left == nullptr) {
        TreeNode* temp = root;
        root = root->right;
        delete temp;
        return root;
      } else {
        TreeNode* insucc = findMin(root->right);
        root->val = insucc->val;
        root->right = deleteNode(root->right, insucc->val);
        return root;
      }
    }
    return root;
  }
};

int main() {

}