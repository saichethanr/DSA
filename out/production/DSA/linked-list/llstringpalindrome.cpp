 #include<bits/stdc++.h> 
using namespace std;

struct Node {
    string data;
    Node *next;

    Node(string x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    bool compute(Node* head) {
       Node *temp=head;
       string str = "";
       while(temp!=nullptr){
           str+=temp->data;
           temp=temp->next;
       }
       
       string s = str;
       reverse(s.begin(),s.end());
       if(s==str){
           return true;
       
           
       }
       return false;
    }
    
};