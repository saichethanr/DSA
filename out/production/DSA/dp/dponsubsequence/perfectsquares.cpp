#include <bits/stdc++.h> 
using namespace std;
 
class Solution {
public:
    int solve(int ind,int n,int &sum){
        if(sum==n){
            return 0;
        }

        if(sum>n || ind *ind>n){
            return INT_MAX;
        }
        
        sum+=(ind*ind);
        int take  = solve(ind,n,sum);
        if(take!=INT_MAX){
            take+=1;
        }
        //backtracking
        sum-=(ind*ind);

        int notake = solve(ind+1,n,sum);
        return min(take,notake);
    }
    int numSquares(int n) {
        int sum=0;
        return solve(1,n,sum);
    }
};

//memoization code
class Solution {
public:
    int solve(int ind,int n,int &sum, vector<vector<int>>&dp){

        if(sum==n){
            return 0;
        }

        if(sum>n || ind *ind>n){
            return INT_MAX;
        }
        if(dp[ind][sum]!=-1){
            return dp[ind][sum];
        }
        
        sum+=(ind*ind);
        int take  = solve(ind,n,sum,dp);
        if(take!=INT_MAX){
            take+=1;
        }
        //backtracking
        sum-=(ind*ind);

        int notake = solve(ind+1,n,sum,dp);
        dp[ind][sum] = min(take,notake);
        return dp[ind][sum];
    }
    int numSquares(int n) {
        int sum=0;
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(1,n,sum,dp);
    }
};