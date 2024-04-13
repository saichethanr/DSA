#include<bits/stdc++.h> 
using namespace std;
//handle the bounds i>0 and j>0
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& a){
         if(i==0 && j==0){
            return a[0][0];
         }
         if(i<0 || j<0){
            return INT_MAX;
         }

         if(dp[i][j]!=-1){
            return dp[i][j];
         }
        
        int up = (i > 0) ? solve(i - 1, j, dp, a) + a[i][j] : INT_MAX;
        int left = (j > 0) ? solve(i, j - 1, dp, a) + a[i][j] : INT_MAX;

         dp[i][j] = min(up,left);
         return dp[i][j];
    }