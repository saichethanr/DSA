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
bool check_mirror(Node *root1,Node * root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL || root1!=NULL && root2==NULL){
        return false;
    }

    if(root1->data!=root2->data){
         return false;
    }
    else{
        return true;
    }
    bool left = check_mirror(root1->left,root2->right);
    bool right = check_mirror(root1->right,root2->left);
    return left&&right;

}
int main(){
   Node * root1 = NULL;
   Node * root2 = NULL;
   cout<<"enter for the tree 1" <<endl;
   root1 = buildtree();
   cout<<"enter for the tree 2"<<endl;
   root2 = buildtree();
   cout<<check_mirror(root1,root2)<<endl;
   return 0;
}



