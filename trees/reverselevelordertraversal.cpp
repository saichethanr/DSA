#include<bits/stdc++.h> 
using namespace std;
struct Node
{
    int data;
    Node* left;
    Node* right;
}; 


vector<int> reverseLevelOrder(Node *root){      
       vector <vector<int>> ans;
       vector <int> a;
        if(root==nullptr){
            return a;
        }
        queue <Node*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector <int> level;
            for(int i=0;i<size;i++){
                Node *node = q.front();
                q.pop();
                if(node->left!=nullptr){
                    q.push(node->left);
                }
                if(node->right!=nullptr){
                    q.push(node->right);
                }
                level.push_back(node->data);

            }
         ans.push_back(level);
        } 
        
        reverse(ans.begin(),ans.end());
        
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[0].size();j++){
                a.push_back(ans[i][j]);
            }
        }
        
        return a;
}