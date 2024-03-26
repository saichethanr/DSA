#include<bits/stdc++.h> 
using namespace std;
int fibrec(int n){
    if(n==0 ||n==1){
        return n;
    }
    int ans = fibrec(n-1) + fibrec(n-2);
    return ans;
}
int fibdptopdown(int n,vector <int> dp){
   //creating a dp array
    if(n==0 ||n==1){
        return n;
    }
    //check if ans alreaduy exists
    if(dp[n]!=-1){
       return dp[n];
    }

    dp[n]  = fibdptopdown(n-1,dp) + fibdptopdown(n-2,dp);
    return dp[n];
}
int fibdpbottomup(int n){
   //creating a dp array
    vector <int> dp(n+1,-1);
    dp[0] = 0;
    dp[1] = 1;
    if(n==0){
        return dp[0];
    }
    if(n==1){
        return dp[1];
    }
    //check if ans alreaduy exists
   for(int i=2;i<=n;i++){
    dp[i] =dp[i-1] +dp[i-2];
   }
   return dp[n];
}
int main(){
    int n=3;
   vector <int> dp (n+1,-1);
//    int ans = fibdptopdown(n,dp);
int ans = fibdpbottomup(n);
 cout<<ans<<endl;
return 0;
}