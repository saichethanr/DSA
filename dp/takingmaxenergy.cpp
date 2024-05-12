#include<bits/stdc++.h> 
#include <vector>
using namespace std;

class Solution {
public:
    int solve(int i,vector<int>& energy, int k,vector<int>&dp){
        int n = energy.size();
        if(i>=n){
            return 0;
        }
         
        if(dp[i]!=-1){
            return dp[i];
        }
        int take  = energy[i] + solve(i+k,energy,k,dp);
        dp[i] = take;
  
        return dp[i];
    
    }
    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        int ans = INT_MIN;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            ans = max(ans,solve(i,energy,k,dp));
        }
        return ans;
    }
};