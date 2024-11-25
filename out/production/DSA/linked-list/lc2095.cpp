
#include<bits/stdc++.h> 
using namespace std;


//  * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


   ListNode* deleteMiddle(ListNode* head) {
        ListNode *temp=head;
        if(head->next==nullptr){
            delete head;
            return nullptr;
        }
        ListNode *prev;
        int size=0;
        while(temp!=nullptr){
            size++;
            temp=temp->next;
        }
        int m=size/2;
        int i=1;
        temp=head;
        while(i<=m){
            prev=temp;
            i++;
            temp=temp->next;
        }
        prev->next=temp->next;
        delete temp;
        return head;


    }