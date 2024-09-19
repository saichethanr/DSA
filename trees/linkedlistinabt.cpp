#include<bits/stdc++.h> 
using namespace std;
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool solve(TreeNode* root,ListNode *temp,int len,int cnt){
         if(root==nullptr){
            return false;
         }
         if(len==cnt){
            return true;
         }
        bool left;
        bool right;
         if(root->val==temp->val){
           left = solve(root->left,temp->next,len,cnt+1);
           right = solve(root->right,temp->next,len,cnt+1);
         }
         else{
           left = solve(root->left,temp,len,0);
           right = solve(root->right,temp,len,0);
         }
        return left||right;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        ListNode *temp=head;
        int len=0;
        while(temp!=nullptr){
           len++;
           temp=temp->next;
        }
        cout<<len<<endl;
        int cnt=0;
       return solve(root,head,len,cnt);
    }
};



