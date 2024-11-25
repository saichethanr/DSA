#include<bits/stdc++.h> 
using namespace std;

string convert2binary(int n){
   string res = "";
   while(n!=1){
    if(n%2==1){
        res+='1';
    }
    else{
        res+='0';
    }
    n/=2;
   }
   res+='1';
   reverse(res.begin(),res.end());
   return res;
}

int main(){
    int n;
    cout<<"enter the number :"<<endl;
    cin>>n;
    string res = convert2binary(n);
    cout<<res<<endl;
}