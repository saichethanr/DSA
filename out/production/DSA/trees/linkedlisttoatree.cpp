#include<bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};


void convert(Node *head, TreeNode *&root) 
    {
        queue<TreeNode*> q;
        root = new TreeNode(head->data);
        head = head->next;
        q.push(root);
        
        while(head != nullptr)
        {
            TreeNode* temp = q.front();
            q.pop();
            
            temp->left = new TreeNode(head->data);
            q.push(temp->left);
            head = head->next;
            
            if(head != nullptr)
            {
                temp->right = new TreeNode(head->data);
                q.push(temp->right);
                head = head->next;
            }
        }
    }



void convert(Node *head, TreeNode *&root) 
    {
        queue<TreeNode*> q;
        root = new TreeNode(head->data);
        head = head->next;
        q.push(root);
        
        while(head != nullptr)
        {
            TreeNode* temp = q.front();
            q.pop();
            
            temp->left = new TreeNode(head->data);
            q.push(temp->left);
            head = head->next;
            
            if(head != nullptr)
            {
                temp->right = new TreeNode(head->data);
                q.push(temp->right);
                head = head->next;
            }
        }
    }