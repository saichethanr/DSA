#include<bits/stdc++.h> 
using namespace std;

void settheithbit(int n,int i){
   int ans = ~(1<<i)&n;
   cout<<ans<<endl;
}
int main(){
  settheithbit(13,2);
}