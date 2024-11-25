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
int diameter(Node *root){
    if(root==NULL){
        return 0;
    }
    int d1 = diameter(root->left);
    int d2= diameter(root->right);
    int d3 = maxdepth(root->left) + maxdepth(root->right);
    int ans = max(d1,max(d2,d3));
    return ans;

}
int main(){

   Node * root = NULL;
   root = buildtree();
   cout<<diameter(root)<<endl;
   return 0;
}



