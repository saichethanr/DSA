#include<bits/stdc++.h> 
using namespace std;

    int solve(int n,vector <int> &dp){
      //base caase 
    if(n==1 || n==2){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = solve(n-1,dp) + solve(n-2,dp);
    return dp[n];

    }
    int climbStairs(int n) {
       vector <int> dp(n+1,-1);
       return solve(n,dp);
    }