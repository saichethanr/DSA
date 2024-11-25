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
void printleftnodes( Node * root){
    //ase case
    //return if root is null
    if(root==NULL){
        return;
    }
    //reurn if root is a leaf node
    if(root->left ==NULL && root->right ==NULL){
        return;
    }

    cout<<root->data<<endl;
    if(root->left){
       printleftnodes(root->left);
    }
   else{
         printleftnodes(root->right);
   }

}
void printrightnodes( Node * root){
    //ase case
    //return if root is null
    if(root==NULL){
        return;
    }
    //reurn if root is a leaf node
    if(root->left ==NULL && root->right ==NULL){
        return;
    }
    if(root->right){
        printrightnodes(root->right);
    }
    else{
      printrightnodes(root->left);
    }
    
    cout<<root->data<<endl;
    
}
void printleafnodes( Node * root){
    //ase case
    //return if root is null
    if(root==NULL){
        return;
    }
    //reurn if root is a leaf node
    if(root->left ==NULL && root->right ==NULL){
        cout<<root->data<<endl;
    }
    
    printleafnodes(root->left);
    printleafnodes(root->right);
}
void boundarytraversal(Node * root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<endl;
        printleftnodes(root->left);
        printleafnodes(root);
        printrightnodes(root->right);
}
int main(){

   Node * root = NULL;
   root = buildtree();
   boundarytraversal(root);
   return 0;
}



