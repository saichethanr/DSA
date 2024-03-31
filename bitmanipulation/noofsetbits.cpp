#include<bits/stdc++.h> 
using namespace std;

int noofsetbits(int n){
   int cnt=0;
   while(n>1){
    if(n%2==1){
        cnt++;
    }
    n/=2;
   }
   if(n==1){
    cnt++;
   }
   return cnt;
}

int main(){
    cout << noofsetbits(13) << endl;
    return 0;
}
