#include <bits/stdc++.h>
using namespace std;
/*
            8
          /   \
        5       10
      /  \     /
     3    6   9
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
Node* insert(Node* root, int val) {
  if(root == nullptr) return new Node(val);
  if(val < root->val) root->left = insert(root->left, val);
  else root->right = insert(root->right, val);
  return root;
}

Node* p;
Node* q;

Node* createBST(vector<int>& arr) {
  Node* root = nullptr;
  for(int x : arr) {
    root = insert(root, x);
    if(x == 10) p = root;
    else if(x == 9) q = root;
  }
  return root;
}

void printTree(Node* root) {
  if(root == nullptr) return;
  printTree(root->left);
  cout<<root->val<< " "; // INORDER
  printTree(root->right);
  return;
}

vector<Node*> pre;
void inorder(Node* root) {
  if(root == nullptr) return;
  pre.push_back(root);
  inorder(root->left);
  inorder(root->right);
}
Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    inorder(root);
    int i = pre.size() - 1;
    while(i >= 0) {
      if(pre[i] == p || pre[i] == q) {
        if(i > 0 and (pre[i - 1] == p or pre[i - 1] == q)) {
          if(i - 2 >= 0) return pre[i - 2];
          else return pre[i - 1];
        } else {
          i--;
          while(pre[i] != p and pre[i] != q){
              i--;
          }
          if(i - 1 >= 0) return pre[i - 1];
        }
      }
      i--;
    }
    return nullptr;
}
int main() {
  vector<int> arr = {6, 5, 8, 10, 9, 3};
  Node* root = createBST(arr);
  printTree(root);
  Node* res = lowestCommonAncestor(root, p, q);
  cout<<" PRINTING>>> "<<endl;
  for(Node* r: pre) {
    cout<<r->val<<" ";
  }
}