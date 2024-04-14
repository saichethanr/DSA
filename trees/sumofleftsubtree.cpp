#include<bits/stdc++.h> 
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    int solve(TreeNode* root){
       if(!root){
        return 0;
       }
        int ans =0;
       if(root->left){
        if(!root->left->left && !root->left->right){
            ans+=root->left->val;
        }
        else{
            ans+=solve(root->left);
        }
     
       }
   ans+=solve(root->right);
        return ans;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int ans = solve(root);
        return ans;
    }
};