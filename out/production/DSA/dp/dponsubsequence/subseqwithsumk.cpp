#include <bits/stdc++.h> 
using namespace std;

// Given an array of non-negative integers, and a value sum, 
// determine if there is a subset of the given set with sum equal to given sum. 


bool subsum_rec(int idx,int target,vector<int> &arr){
    if(target==0){
        return true;
    }
    if(idx==0){
        return (arr[idx]==target);
    }
    bool donttake = subsum_rec(idx-1,target,arr);
    bool take = false;
    if(target>=arr[idx]){
         take = subsum_rec(idx-1,target-arr[idx],arr);
    }
    return donttake || take;
}

bool  subsum_memo(int idx,int target,vector<int> &arr,vector<vector<int>>dp){
    if(target==0){
        return true;
    }
    if(idx==0){
       return (arr[0]==target);
    }
    if(dp[idx][target]!=-1){
        return dp[idx][target];
    }
    bool  donttake = subsum_memo(idx-1,target,arr,dp);
    bool take = false;
    if(target>=arr[idx]){
         take = subsum_memo (idx-1,target-arr[idx],arr,dp);
    }
    dp[idx][target] = donttake | take;
    return dp[idx][target];
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector <vector<bool>> dp(n+1,vector<bool>(k+1,0));
    for(int i=0;i<n;i++){
        dp[i][0] = true;
    }
    //consider a single element and develop this base case
    dp[0][arr[0]]=true;

    for(int i=1;i<n;i++){
        for(int j=1;j<=k;j++){
            bool  donttake = dp[i-1][j];
            bool take = false;
            if(j>=arr[i]){
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = donttake|take;
        }
    }
    return dp[n-1][k];
}