#include<bits/stdc++.h> 
using namespace std;

int noofzerobits(int n){
    int cnt =0;
    while(n>1){
        if(!(n&1)){
            cnt++;
        }
        n=n>>1;
    }
    return cnt;
}
int main(){
  cout<<noofzerobits(8)<<endl;
}