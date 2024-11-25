#include<bits/stdc++.h> 
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};


class Solution {
  public:
    void solve(vector<int>&v,vector<vector<int>>&ans,Node *root){
        if(root==nullptr){
            return;
        }
         v.push_back(root->data);
        if(root->left==nullptr &&root->right==nullptr){
            ans.push_back(v);
        }
        else{
            if(root->left){
                solve(v,ans,root->left);
            }
        
            if(root->right){
                solve(v,ans,root->right);
            }
        }
        v.pop_back();
        
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        if(root==nullptr){
            return ans;
        }
        vector<int>v;
        solve(v,ans,root);
        return ans;
    }
};