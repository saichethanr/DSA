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

    void levelorder(Node * root){
        queue <Node*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node *temp = q.front();
            q.pop();
            if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
            }
            else{
                cout<<temp->data<<endl;

            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            }
        
        }

    }

int main(){
   Node * root = NULL;
   root = buildtree();
   levelorder(root);
   return 0;
}



