#include <bits/stdc++.h> 
using namespace std;

int solve(int idx,int w,vector<int> &val,vector<int> &wt){
    if(idx==0){
           //how many times wt[0] can only be considered to make profit*val
           return (int)(w/wt[0])*val[0];

    }
   
    int notake = 0 +solve(idx-1,w,val,wt);
    int take = INT_MIN;
    if(wt[idx]<=w){
       take = val[idx] + solve(idx,w-wt[idx],val,wt);
    }

    return max(take,notake);
}


int solve(int idx,int w,vector<int> &val,vector<int> &wt, vector<vector<int>>&dp){
    if(idx==0){
 
           return (int)(w/wt[0])*val[0];

    }
    if(dp[idx][w]!=-1){
        return dp[idx][w];
    }
    int notake = 0 +solve(idx-1,w,val,wt,dp);
    int take = INT_MIN;
    if(wt[idx]<=w){
       take = val[idx] + solve(idx,w-wt[idx],val,wt,dp);
    }
    dp[idx][w] = max(take,notake);
    return dp[idx][w] ;
}

int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt) {
    vector<vector<int>>dp(n,vector<int>(w+1,0));
    for(int i=0;i<=w;i++){
        dp[0][i] = (i/wt[0])*val[0];
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=w;j++){
            int notake = 0 +dp[i-1][j];
            int take = INT_MIN;
            if(j>=wt[i]){
            take = val[i] + dp[i][j-wt[i]];
            }
            dp[i][j] = max(take,notake);
        }
    }
    return dp[n-1][w];
}