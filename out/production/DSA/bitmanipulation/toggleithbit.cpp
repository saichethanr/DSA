#include<bits/stdc++.h> 
using namespace std;

void settheithbit(int n,int i){
    int ans;
  if(n&(1<<i)){
    ans = ~(1<<i)&n;
  }
  else{
     ans = (1<<i)|n;
  }
  cout<<ans<<endl;
}
int main(){
  settheithbit(13,2);
}