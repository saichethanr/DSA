#include<bits/stdc++.h> 
using namespace std;

bool ithbitsetornot_leftshift(int n ,int i){
  if(n&(1<<i)){
    return true;
  }
  return false;
}
bool ithbitsetornot_rightshift(int n,int i){
   if(1&(n>>i)){
    return true;
   }
   return false;
}
int main(){
  cout<<ithbitsetornot_leftshift(13,1)<<endl;
  cout<<ithbitsetornot_rightshift(13,0)<<endl;
}