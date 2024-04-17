  #include<bits/stdc++.h> 
using namespace std;


// You are given the root of a binary tree where each node has a value in the range [0, 25] representing the letters 'a' to 'z'.

// Return the lexicographically smallest string that starts at a leaf of this tree and ends at the root.

// As a reminder, any shorter prefix of a string is lexicographically smaller.

// For example, "ab" is lexicographically smaller than "aba".
// A leaf of a node is a node that has no children.

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  void dfs(TreeNode *root,string path,string &s){
        if(root==nullptr){
            return;
        }

        path.push_back(char(root->val + 'a'));

        if(root->left==nullptr && root->right==nullptr){
            reverse(path.begin(),path.end());
            if(s.empty() || path<s){
                s=path;
            }
        }
        dfs(root->left,path,s);
        dfs(root->right,path,s);
    }
    string smallestFromLeaf(TreeNode* root) {
        string s =  "";
        string path="";
        dfs(root,path,s);
        return s;
    }