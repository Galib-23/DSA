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

void printTree(Node* root) {
  if(root == nullptr) return;
  cout<<root->val<< " ";
  printTree(root->left);
  printTree(root->right);
  return;
}

int main() {
  Node* n1 = new Node(2);
  Node* n2 = new Node(4);
  Node* n3 = new Node(6);
  Node* n4 = new Node(8);
  Node* n5 = new Node(10);
  Node* n6 = new Node(7);

  //level 1
  n1->left = n2;
  n1->right = n3;

  //level 2
  n2->parent = n3->parent = n1;
  n2->left = n4;
  n2->right = n5;
  n3->left = n6;

  //level 3
  n4->parent = n5->parent = n2;
  n6->parent = n3;

  printTree(n1);
}