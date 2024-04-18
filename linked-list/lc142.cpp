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
 ListNode *detectCycle(ListNode *head) {
               unordered_map<ListNode*,int>mpp;
        ListNode *temp=head;
        while(temp!=nullptr){
            if(mpp.find(temp)!=mpp.end()){
                return temp;
            }
            mpp[temp]++;
            temp=temp->next;
        }
        return nullptr;
    }