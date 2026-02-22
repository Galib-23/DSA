#include <bits/stdc++.h>
using namespace std;

class MyCircularQueue {
public:
    struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        val = x;
        next = nullptr;
      }
    };
    int n;
    int currSize;
    ListNode* front;
    ListNode* rear;
    ListNode* head;
    MyCircularQueue(int k) {
      this->n = k;
      this->front = NULL;
      this->rear = NULL;
      this->currSize = 0;
    }

    bool enQueue(int value) {
      if(currSize == n) {
        return false;
      } else {
        if(rear == NULL) {
          ListNode *newNode = new ListNode(value);
          rear = front = head = newNode;
        }else if(rear->next != NULL) {
          rear->next->val = value;
          rear = rear->next;
        } else {
          ListNode *newNode = new ListNode(value);
          rear->next = newNode;
          rear = newNode;
        }
        currSize++;
        if(currSize == n) {
          rear->next = head;
        }
      }
      return true;
    }
    
    bool deQueue() {
      if(currSize) {
        front->val = -1;
        front = front->next;
        currSize--;
        return true;
      }
      return false;
    }
    
    int Front() {
      if(currSize) return front->val;
      return -1;
    }
    
    int Rear() {
      if(currSize) return rear->val;
      return -1;
    }
    
    bool isEmpty() {
      if(currSize == 0) return true;
      return false;
    }
    
    bool isFull() {
      if(currSize == n) return true;
      return false;
    }
};

int main() {

}