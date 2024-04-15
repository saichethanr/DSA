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
 
// remember what need to be done at every node do it first .. 
// and then check if it can bbe done to left 
// and check the same for right
// and check for both left and right 


 void solve(TreeNode* root,string s,vector<string>&v){
        if(root==nullptr){
            return;
        }
        s+=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr){
            v.push_back(s);
        }
        else if(root->left==nullptr){
            solve(root->right,s,v);
        }
        else if(root->right==nullptr){
            solve(root->left,s,v);
        }
        else{
            solve(root->left,s,v);
            solve(root->right,s,v);
        }
    }
    int sumNumbers(TreeNode* root) {
        string s = "";
        vector<string> v;
        solve(root,s,v);
        int sum=0;
        for(int i=0;i<v.size();i++){
          sum+=stoi(v[i]);
        }
        return sum;
    }