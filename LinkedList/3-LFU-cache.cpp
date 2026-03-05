#include <bits/stdc++.h>
using namespace std;

class LFUCache {
public:
  struct ListNode {
    int key;
    int value;
    ListNode* next;
    ListNode* prev;

    ListNode(int key, int val) {
      this->key = key;
      this->value = val;
      this->next = nullptr;
      this->prev = nullptr;
    }
  };
  int capacity;

  unordered_map<int, pair<ListNode*, int>> m;
  map<int, pair<ListNode*, ListNode*>> fm;

  LFUCache(int capacity) {
    this->capacity = capacity;
  }
  
  int get(int key) {
    if(m.find(key) == m.end()) return -1;
    ListNode* keyNode = m[key].first;
    int prevCount = m[key].second;
    int newCount = prevCount + 1;
    m[key].second = newCount;
    if(keyNode->prev == nullptr and keyNode->next == nullptr) {
      fm.erase(prevCount);
    } else if(keyNode->next == nullptr) {
      fm[prevCount].second = keyNode->prev;
      fm[prevCount].second->next = nullptr;
    } else if(keyNode->prev == nullptr) {
      fm[prevCount].first = keyNode->next;
      fm[prevCount].first->prev = nullptr;
    } else {
      keyNode->prev->next = keyNode->next;
      keyNode->next->prev = keyNode->prev;
    }
    keyNode->prev = keyNode->next = nullptr;
    if(fm.find(newCount) == fm.end()) {
      fm[newCount] = {keyNode, keyNode};
    } else {
      fm[newCount].first->prev = keyNode;
      keyNode->next = fm[newCount].first;
      fm[newCount].first = keyNode;
    }
    return keyNode->value;
  }
  
  void put(int key, int value) {
    if(m.find(key) != m.end()) {
      ListNode* keyNode = m[key].first;
      keyNode->value = value;
      int prevCount = m[key].second;
      int newCount = prevCount + 1;
      m[key].second = newCount;
      if(keyNode->prev == nullptr and keyNode->next == nullptr) {
        fm.erase(prevCount);
      } else if(keyNode->next == nullptr) {
        fm[prevCount].second = keyNode->prev;
        fm[prevCount].second->next = nullptr;
      } else if(keyNode->prev == nullptr) {
        fm[prevCount].first = keyNode->next;
        fm[prevCount].first->prev = nullptr;
      } else {
        keyNode->prev->next = keyNode->next;
        keyNode->next->prev = keyNode->prev;
      }
      if(fm.find(newCount) == fm.end()) {
        keyNode->prev = keyNode->next = nullptr;
        fm[newCount] = {keyNode, keyNode};
      } else {
        keyNode->prev = nullptr;
        fm[newCount].first->prev = keyNode;
        keyNode->next = fm[newCount].first;
        fm[newCount].first = keyNode;
      }
    } else {
      ListNode* newNode = new ListNode(key, value);
      if(m.size() == this->capacity) {  
        if(this->capacity == 0) return;
        ListNode* tmpHead = (*fm.begin()).second.first;
        ListNode* tmpTail = (*fm.begin()).second.second;
        if(tmpHead == tmpTail and tmpTail != nullptr) {
          m.erase(tmpTail->key);
          fm.erase(fm.begin());
          delete tmpTail;
          m[key] = {newNode, 1};
          if(fm.find(1) == fm.end()) {
            fm[1] = {newNode, newNode};
          } else {
            fm[1].first->prev = newNode;
            newNode->next = fm[1].first;
            fm[1].first = newNode;
          }
        } else {
          (*fm.begin()).second.second = tmpTail->prev;
          tmpTail->prev->next = nullptr;
          
          m.erase(tmpTail->key);
          delete tmpTail;

          m[key] = {newNode, 1};
          if(fm.find(1) == fm.end()) {
            fm[1] = {newNode, newNode};
          } else {
            fm[1].first->prev = newNode;
            newNode->next = fm[1].first;
            fm[1].first = newNode;
          }
        }
      } else {
        m[key] = {newNode, 1};
        if(fm.find(1) == fm.end()) {
          fm[1] = {newNode, newNode};
        } else {
          fm[1].first->prev = newNode;
          newNode->next = fm[1].first;
          fm[1].first = newNode;
        }
      }
    }
  }
};



int main() {
  
}
