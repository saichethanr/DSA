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
int sumtree(Node * root){
    //base case
    if(root==NULL){
        return 0;
    }

    int leftans = sumtree(root->left);
    int rightans = sumtree(root->right);
    root->data = leftans + root->data + rightans;
    cout<<root->data<<endl;
    return root->data;
}
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

int main(){
   Node * root = NULL;
   root = buildtree();
   sumtree(root);
   return 0;
}



