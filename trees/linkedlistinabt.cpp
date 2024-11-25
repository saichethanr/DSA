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



//one of the best question
class Solution {
public:
    bool solve(TreeNode* root, ListNode *temp) {
        // If linked list is fully traversed, return true
        if (temp == nullptr) {
            return true;
        }
        // If binary tree is fully traversed or doesn't match linked list value, return false
        if (root == nullptr || root->val != temp->val) {
            return false;
        }
        // Recursively check both left and right subtree for matching path
        return solve(root->left, temp->next) || solve(root->right, temp->next);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        // If the binary tree is fully traversed, return false (no path found)
        if (root == nullptr) {
            return false;
        }
        // Check if the current node in the binary tree is the start of a matching path
        // or continue searching in the left and right subtrees
        return solve(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};
