#include <bits/stdc++.h>
using namespace std;
/*
            2
          /   \
        4       6
      /  \     /
     8   10   7
*/
struct Node {
  int val;
  Node* left;
  Node* right;
  Node* parent;
  Node(int val) {
    this->val = val;
    this->right = this->left = this->parent = nullptr;
  };
};

Node* createTreeFromPreorderArray(vector<int>& preorder, int& i) {
  if(i >= preorder.size() || preorder[i] == -1) {
    i++;
    return nullptr;
  };
  Node* newNode = new Node(preorder[i]);
  i++;
  newNode->left = createTreeFromPreorderArray(preorder, i);
  newNode->right = createTreeFromPreorderArray(preorder, i);
  return newNode;
}

void printTree(Node* root) {
  if(root == nullptr) return;
  printTree(root->left);
  cout<<root->val<< " ";
  printTree(root->right);
  return;
}



int main() {
  vector<int> preorder = {2, 4, 8, -1, -1, 10, -1, -1, 6, 7, -1, -1};
  int i = 0;
  Node* root = createTreeFromPreorderArray(preorder, i);
  printTree(root);
}