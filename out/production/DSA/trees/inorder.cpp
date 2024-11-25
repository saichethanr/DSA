#include<bits/stdc++.h> 
using namespace std;
class Node{
    public: 
    int data;
    Node *left;
    Node *right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node * buildtree(){
    int data;
    cout<<"enter the data"<<endl;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    Node *root = new Node(data);
    cout<<"enetr the dtaa for the left part of data"<<data<<endl;
    root->left = buildtree();
    cout<<"enetr the dtaa for the right part of data"<<data<<endl;
    root->right = buildtree();
    return root;
}
void inorder(Node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<endl;
    inorder(root->right);
}
int main(){

   Node * root = NULL;
   root = buildtree();
   inorder(root);
   return 0;
}



