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