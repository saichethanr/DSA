#include<bits/stdc++.h> 
using namespace std;

void swap2num(int a ,int b){
    a = a^b;
    b=a^b;
    a=a^b;
    cout<<a<<endl;
    cout<<b<<endl;
}
int main(){
  swap2num(3,4);
}