#include <bits/stdc++.h> 
using namespace std;


// Given an integer array nums, return true if you can partition the array into two subsets such that 
// the sum of the elements in both subsets is equal or false otherwise.


class Solution {
public:
    bool solve(int target,int n,vector<int>&nums,vector<vector<bool>>&dp){
         for(int i=0;i<nums.size();i++){
            dp[i][0] = true;
         }
         
         dp[0][nums[0]]=true;

         for(int i=1;i<nums.size();i++){
            for(int j=1;j<=target;j++){
                bool donttake = dp[i-1][j];
                bool take = false;
                if(j>=nums[i]){
                    take = dp[i-1][j-nums[i]];
                }
                dp[i][j] = take | donttake;
            }
         }
         return dp[n-1][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false; 
        }
        int n = nums.size();
        vector<vector<bool>> dp(nums.size(),vector<bool>(sum,0));
        int target = sum/2;
        bool ans = solve(target,n,nums,dp);
        return ans;
    }
};