#include<bits/stdc++.h> 
using namespace std;


void printabcmatrix(int n){
    int k=1;
    int p=0;
    for(char i = 'a'; i <= 'z'; i++) {
         cout<<i<<" ";
         if(k%n==0 && k!=0){
            cout<<endl;
            p++;
         }

         if(p==n){
            break;
         }
         k++;
    }
}

int main(){
    int n;
    cout<<"enter the size of the square:"<<endl;
    cin>>n;
    printabcmatrix(n);
}