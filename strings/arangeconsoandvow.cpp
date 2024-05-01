#include<bits/stdc++.h> 
#include <string>
using namespace std;



struct Node
{
    char data;
    struct Node *next;

    Node(char x){
        data = x;
        next = NULL;
    }

};

// Given a singly linked list having n nodes containing english alphabets ('a'-'z'). Rearrange the linked list in such
//  a way that all the vowels come before the consonants while maintaining the order of their arrival. 

class Solution {
  public:
    // task is to complete this function
    // function should return head to the list after making
    // necessary arrangements
    struct Node* arrangeCV(Node* head) {
       set <char> vowel = {'a','e','i','o','u'};
       Node *temp = head;
       vector <int> vow;
       vector <int> conso;
       vector <int> t;
       while(temp!=nullptr){
           if(vowel.find(temp->data)!=vowel.end()){
               vow.push_back(temp->data);
           }
           else{
               conso.push_back(temp->data);
           }
           temp=temp->next;
       }
     t.insert(t.end(), vow.begin(), vow.end());
         t.insert(t.end(), conso.begin(), conso.end());

       temp = head;
       int i =0;
       while(temp!=nullptr && i<t.size()){
         temp->data = t[i];
         i++;
         temp=temp->next;
       }
       
       return head;
    }
};