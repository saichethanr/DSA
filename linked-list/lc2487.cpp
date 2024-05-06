
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
   ListNode* reverseList(ListNode* head) {
        ListNode *temp=head;
        ListNode *prev=nullptr;
        while(temp!=nullptr){
        ListNode *nextnode=temp->next;
           temp->next=prev;
           prev=temp;
           temp=nextnode;
        }
        return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        if (!head || !head->next) {
            return head;
        }

        std::stack<ListNode*> stk;
        ListNode* newHead = nullptr;
        ListNode* temp = nullptr;

        while (head) {
            while (!stk.empty() && head->val > stk.top()->val) {
                stk.pop();
            }

            stk.push(head);

            head = head->next;
        }

        while (!stk.empty()) {
            ListNode* current = stk.top();
            stk.pop();

            if (!newHead) {
                newHead = current;
                temp = newHead;
            } else {
                temp->next = current;
                temp = current;
            }
        }

        temp->next = nullptr;
        newHead=reverseList(newHead);
        return newHead;
    }
};