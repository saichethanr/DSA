#include<bits/stdc++.h> 
using namespace std;

class Stack{
    //properties
    public:
    int *arr;
    int top;
    int size;
     
    //constructor    
    Stack(int size){
        this->size = size;
        arr = new  int[size];
        top=-1;
    }

    void push(int element){
       //check if space available or not size-top>1 
       if(size-top>1){
        top++;
        arr[top] = element;
       }
       else{
        cout<<"handle stack overflow"<<endl;
       }
    }

    void pop(){
        if(top>=0){
            top--; 
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }

    int peek(){
       if(top>=0 && top<size){
         return arr[top];
       }
       else{
        cout<<"stack is empty"<<endl;\
        return -1;
       }
    }
     
     bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
     }
    //behaviur
};


int main(){

    Stack st(5);
    st.push(22);
    st.push(24);
    st.push(44); 

    cout<<st.peek()<<endl;
    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;
    return 0;
}