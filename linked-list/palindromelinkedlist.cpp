
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
    bool isPalindrome(ListNode* head) {
        vector <int> pal;
        ListNode * temp = head;
        while(temp!=nullptr){
            pal.push_back(temp->val);
            temp=temp->next;
        }

        vector <int> rev(pal);
        reverse(rev.begin(),rev.end());
        if(rev==pal){
            return true;
        }
        return false;
    }
};