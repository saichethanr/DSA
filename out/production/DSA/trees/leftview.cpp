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
    cout<<"enetr the datafor the left part of data"<<data<<endl;
    root->left = buildtree();
    cout<<"enetr the data for the right part of data"<<data<<endl;
    root->right = buildtree();
    return root;
}
void printleftview(Node *root, vector <int> &v,int level){
    if(root==NULL){
        return;
    }
    if(v.size() == level){
      v.push_back(root->data);
    }
    printleftview(root->left,v,level+1);
    printleftview(root->right,v,level+1);
}
int main(){

   Node * root = NULL;
   root = buildtree();
   vector <int> v;
   int level =0;
   printleftview(root,v,level);
   for(int i=0;i<v.size();i++){
    cout<<v[i]<<endl;
   }
   return 0;
}



