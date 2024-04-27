#include <bits/stdc++.h> 
using namespace std;

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.


//fewer number of cons that is needed to make that amount
 int solve(int idx,vector <int> &coins,int amount){
   if(idx==0){
    if(amount%coins[idx]==0){
        return amount/coins[idx];
    }
    else{
        return 1e9;
    }
   }

   int notake = solve(idx-1,coins,amount);
   int take = 1e9;
   if(amount>=coins[idx]){
    take = 1 + solve(idx,coins,amount-coins[idx]);
   }

   return min(take,notake);
}

int solve(int idx,vector <int> &coins,int amount,vector<vector<int>>&dp){
   if(idx==0){
    if(amount%coins[idx]==0){
        return amount/coins[idx];
    }
    else{
        return 1e9;
    }
   }
   
   if(dp[idx][amount]!=-1){
    return dp[idx][amount];
   }

   int notake = solve(idx-1,coins,amount,dp);
   int take = 1e9;
   if(amount>=coins[idx]){
    take = 1 + solve(idx,coins,amount-coins[idx],dp);
   }

   dp[idx][amount] = min(take,notake);
   return dp[idx][amount];
}

int solve(vector <int> &coins,int amount,vector<vector<int>>&dp){
int n = coins.size();

   for(int i=0;i<=amount;i++){
     if(i%coins[0]==0){
        dp[0][i] = i/coins[0];
     }
     else{
        dp[0][i] =1e9;
    }
   }
    
   for(int i=1;i<n;i++){
     for(int j=0;j<=amount;j++){
        int notake = dp[i-1][j];
        int take = 1e9;
        if(j>=coins[i]){
            take = 1 + dp[i][j-coins[i]];
        }

        dp[i][j] = min(take,notake);
     }
   }
 
 
   return dp[n-1][amount];
}