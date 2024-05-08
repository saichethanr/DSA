
#include<bits/stdc++.h> 
using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    void deleteNode(ListNode* node) {
       ListNode * delnode = node->next;
       node->val = node->next->val;
       node->next = node->next->next;
       delete delnode;

    }
};