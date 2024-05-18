 #include<bits/stdc++.h> 
using namespace std;

    int solve(int ind,int prev,vector<int>&nums){
        //if the index goes out of bounds 
        if(ind==nums.size()){
            return 0;
        }
        // if the element at current index is not taken  prev is not changed
        int notake = solve(ind+1,prev,nums);
        int take = 0;

        // if the prev = -1 and the nums at ind is greater than nums at prev then it can be taken 
        // for increasing subsequence
        if(prev==-1 || nums[ind]>nums[prev]){
            take = 1 + solve(ind+1,ind,nums);
        }
        
        //max has to be returened
        return max(notake,take);
    }

        //memoization code
        //as initially the prev ==-1 we cannot store that in the dp hence its 
        //important to consider the coordinate change 
        int solve(int ind,int prev,vector<int>&nums, vector<vector<int>> &dp){
        //if the index goes out of bounds 
        if(ind==nums.size()){
            return 0;
        }

        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }
        // if the element at current index is not taken  prev is not changed
        int notake = solve(ind+1,prev,nums,dp);
        int take = 0;

        // if the prev = -1 and the nums at ind is greater than nums at prev then it can be taken 
        // for increasing subsequence
        if(prev==-1 || nums[ind]>nums[prev]){
            take = 1 + solve(ind+1,ind,nums,dp);
        }
        
        //max has to be returened
         dp[ind][prev+1] = max(notake,take);
         return dp[ind][prev+1];
    }
    

     int lengthOfLIS(vector<int>& nums) {

        //for the memoization and recursion we have done bottom up but
        //for the same in tabulation we have to to do top down 
        //a reverse function for the both
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
    
        //base case
        for(int ind=n-1;ind>=0;ind--){
            for(int prev = ind-1;prev>=-1;prev--){
                   // if the element at current index is not taken  prev is not changed
                    int notake = dp[ind+1][prev+1];
                    int take = 0;

                    // if the prev = -1 and the nums at ind is greater than nums at prev then it can be taken 
                    // for increasing subsequence
                    if(prev==-1 || nums[ind]>nums[prev]){
                        take = 1 + dp[ind+1][ind+1];
                    }
                    
                    //max has to be returened
                    dp[ind][prev+1] = max(notake,take);
            }
        }
        return dp[0][-1+1];
    }

    //space optimized approach
   int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
         vector<int>dp(n,1);
         int maxi = INT_MIN;
         for(int ind=0;ind<n;ind++){
              for(int prev=0;prev<ind;prev++){
                if(nums[prev]<nums[ind]){
                    dp[ind] =  max(dp[ind],1 + dp[prev]);
                }  
              }
              maxi = max(maxi,dp[ind]);
         }
         return maxi;
    }
