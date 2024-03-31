#include<bits/stdc++.h> 
using namespace std;

int noofsetbits_approach1(int n){
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
int noofsetbits_approach2(int n){
    int cnt =0;
    while(n>1){
        if(n&1){
            cnt++;
        }
        n=n>>1;
    }
    if(n==1){
        cnt++;
    }
    return cnt;
}

int noofsetbits_approach3(int n){
    int cnt =0;
    while(n!=0){
        n = n&(n-1);
        cnt++;
    }
   
    return cnt;
}


int main(){
    cout << noofsetbits_approach2(8) << endl;
    return 0;
}
