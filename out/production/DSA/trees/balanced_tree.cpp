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
int maxdepth(Node *root){
    if(root==NULL){
        return 0;
    }

    int leftans = maxdepth(root->left);
    int rightans = maxdepth(root->right);
    int ans = max(leftans,rightans) +1 ;
    return ans;
}
bool isbalanced(Node *root){
    if(root==NULL){
        return true;
    }

    int lefth = maxdepth(root->left);
    int righth = maxdepth(root->right);
    int diff = abs(lefth-righth);

    bool ans  = (diff<=1);
    bool lefta = isbalanced(root->left);
    bool righta = isbalanced(root->right);
    if(ans &&  lefta && righta){
        return true;
    }
    else{
        return false;
    }
}
int main(){

   Node * root = NULL;
   root = buildtree();
   cout<<isbalanced(root)<<endl;
   return 0;
}



