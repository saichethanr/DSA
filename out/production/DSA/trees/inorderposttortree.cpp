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

int findpos(int inorder [],int element,int size){
    for(int i=0;i<size;i++){
         if(inorder[i]==element){
            return i;
         }
    }
    return -1;
}
Node * buildtreefrompreorderinorder(int inorder [] ,int preorder [],int size,int &preindex,int inorderstart,int inorderend){
    //baase case
    if(preindex>size || inorderstart >inorderend){
         return NULL;
    }
    int element = preorder[preindex++];
    Node *root = new Node(element);
    int pos = findpos(inorder,element,size);
    root->left = buildtreefrompreorderinorder(preorder,inorder,size,preindex,inorderstart,pos-1);
    root->right = buildtreefrompreorderinorder(preorder,inorder,size,preindex,pos+1,inorderend);
    return root;
}
 void levelorder(Node* root ) {
	queue<Node*> q;
	//initially
	q.push(root);
	q.push(NULL);

	while(!q.empty()) {
		//A
		Node* temp = q.front();
		//B
		q.pop();
		
		if(temp == NULL) {
			cout << endl;
			if(!q.empty()) {
				q.push(NULL);
			}	
		}
		else {
			//C
			cout << temp->data << " ";
			//D
			if(temp -> left) {
				q.push(temp ->left);
			}
			if(temp ->right) {
				q.push(temp->right);
			}
		}
		
		
	}
}
int main(){
   int preorder[] = {10,20,40,50,30,60,70};
   int inorder[] = {40,20,50,10,60,30,70};
   int preindex = 0;
   int size = 7;
   int inorderstart=0;
   int inorderend=size-1;
    Node * root = buildtreefrompreorderinorder(inorder,preorder,size,preindex,inorderstart,inorderend);
   levelorder(root);
   return 0;
}



