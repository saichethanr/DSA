
#include<bits/stdc++.h> 
using namespace std;


Node* removeAllDuplicates(struct Node* head) {
        // code here
        Node * temp=head;
        Node * prev=NULL;
        while(temp!=NULL){
            int cnt=0;
            while(temp&&temp->next){
                if(temp->data==temp->next->data){
                    cnt++;
                    temp=temp->next;
                }
                else{
                    break;
                }
                
            }
            if(cnt>0){
                if(prev==NULL){
                    head=temp->next;
                    temp=head;
                }
                else{
                    prev->next=temp->next;
                    temp=temp->next;
                }
            }else{
            prev=temp;
            temp=temp->next;
            }
        }
        return head;
    }