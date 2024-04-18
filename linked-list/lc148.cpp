
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


class Solution {
public:
    ListNode* sortList(ListNode* head) {
       vector <int> a;
       ListNode *temp=head;
       while(temp!=nullptr){
           a.push_back(temp->val);
           temp=temp->next;
       } 
       sort(a.begin(),a.end());
       temp=head;
       int i=0;
       while(temp!=nullptr && i<a.size()){
           temp->val=a[i];
           i++;
           temp=temp->next;
       }
       return head;
    }
};