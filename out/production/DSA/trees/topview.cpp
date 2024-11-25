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

void printtopview(Node *root){
if(root==NULL){
    return;
}
map <int,int> mpp;
queue <pair<Node *,int> > q;
q.push(make_pair(root,0));

while(!q.empty()){
    pair <Node *,int> f = q.front();
    q.pop();
    int hd=  f.second;
    Node * node = f.first;
    if(mpp.find(hd)==mpp.end()){
        mpp[hd]=node->data;
    }
    if(node->left){
        q.push(make_pair(node->left,hd-1));
    }
    if(node->right){
        q.push(make_pair(node->right,hd+1));
    }
}
for(auto it : mpp){
    cout<<it.first<<" " <<it.second<<endl;
}
}
int main(){

   Node * root = NULL;
   root = buildtree();
   printtopview(root);
   return 0;
}



