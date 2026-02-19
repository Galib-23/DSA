#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
      this->data = val;
      this->next = NULL;
    }
};

class List {
  Node* head;
public:
  List() {
    head = NULL;
  }

  void push_front(int val) {
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    return;
  }

  void push_back(int val) {
    Node *newNode = new Node(val);
    if(head == NULL) {
      head = newNode;
      return;
    }
    Node *temp = head;
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }

  void push_to_pos(int val, int pos) {
    Node *temp = head;
    --pos;
    while(pos > 0) {
      temp = temp->next;
      pos--;
    }
    Node *newNode = new Node(val);
    newNode->next = temp->next;
    temp->next = newNode;
    return;
  }

  void pop_front() {
    if(head == NULL) return;
    Node *temp = head;
    head = head->next;
    delete temp;
  }

  void pop_back() {
    if(head == NULL) return;
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
}

  void print_ll() {
    cout<<"Printing...\n";
    Node *temp = head;
    while(temp != NULL){
      cout<<temp->data<<" ";
      temp = temp->next;
    }
    cout<<endl;
  }
};

int main () {
  List *l = new List();
  // l->push_front(3);
  // l->push_front(4);
  // l->push_front(5);

  l->push_back(1);
  l->push_back(2);
  l->push_back(3);
  l->push_back(4);

  //l->pop_back();
  l->push_to_pos(7, 3);

  l->print_ll();
}