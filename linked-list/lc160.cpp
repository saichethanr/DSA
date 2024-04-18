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
  
 ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> nodes_set;

        // Traverse the first linked list and store nodes in the set
        ListNode *temp1 = headA;
        while (temp1 != nullptr) {
            nodes_set.insert(temp1);
            temp1 = temp1->next;
        }

        // Traverse the second linked list and check if a node is in the set
        ListNode *temp2 = headB;
        while (temp2 != nullptr) {
            if (nodes_set.find(temp2) != nodes_set.end()) {
                return temp2;
            }
            temp2 = temp2->next;
        }

        return nullptr;
    }