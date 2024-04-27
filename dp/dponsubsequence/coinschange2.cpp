#include <bits/stdc++.h> 
using namespace std;
 

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

// You may assume that you have an infinite number of each kind of coin.

// The answer is guaranteed to fit into a signed 32-bit integer.


//  simple recursion
  int solve(int idx,int target,vector<int>& coins,vector<vector<int>> &dp){
        
        if(idx==0){
            if(target%coins[idx]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        
        int notake = solve(idx-1,target,coins,dp);
        int take =0;
        if(target>=coins[idx]){
            take = solve(idx,target-coins[idx],coins,dp);
        }
        return take + notake;
    }


//   memoization
  int solve(int idx,int target,vector<int>& coins,vector<vector<int>> &dp){
        
        if(idx==0){
            if(target%coins[idx]==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(dp[idx][target]!=-1){
            return dp[idx][target];
        }

        int notake = solve(idx-1,target,coins,dp);
        int take =0;
        if(target>=coins[idx]){
            take = solve(idx,target-coins[idx],coins,dp);
        }
        dp[idx][target] = take + notake;
        return dp[idx][target];
    }

    //tabulation
      int solve(int target,vector<int>& coins,vector<vector<int>> &dp){
        
        int n = coins.size();
        for(int i=0;i<=target;i++){
            if(i%coins[0]==0){
                dp[0][i] = 1;
            }
            else{
                dp[0][i]=0;
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<=target;j++){
               int notake = dp[i-1][j];
               int take =0;
                if(j>=coins[i]){
                    take = dp[i][j-coins[i]];
                }
                dp[i][j] = take + notake;
            }
        }

        
        return dp[n-1][target];
    }