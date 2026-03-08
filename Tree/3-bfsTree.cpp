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

void bfs(Node* root, queue<Node*>& q) {
  while(!q.empty()) {
    cout<<q.front()->val<<" ";
    if(q.front()->left != nullptr) q.push(q.front()->left);
    if(q.front()->right != nullptr) q.push(q.front()->right);
    q.pop();
    if(q.front() == nullptr and q.size() == 1) {
      break;
    } else if(q.front() == nullptr and q.size() > 1) {
      q.pop();
      q.push(nullptr);
      cout<<endl;
    }
  }
}

int main() {
  vector<int> preorder = {2, 4, 8, -1, -1, 10, -1, -1, 6, 7, -1, -1};
  int i = 0;
  Node* root = createTreeFromPreorderArray(preorder, i);
  queue<Node*> q;
  q.push(root);
  q.push(nullptr);
  bfs(root, q);
}