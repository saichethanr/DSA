#include <bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int sum =0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int n = nums.size();
        vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));

        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        
        if(nums[0]<=sum){
            dp[0][nums[0]] = true;
        }
        
        for(int i=1;i<n;i++){
           for(int j=1;j<=sum;j++){
              bool donttake = dp[i-1][j];
              bool take = false;
              if(j>=nums[i]){
                 take = dp[i-1][j-nums[i]];
              }
              dp[i][j] = take | donttake;
           }
        }

       int mindiff = INT_MAX;
        for(int i=0;i<=sum/2;i++){
             if(dp[n-1][i]==true){
                mindiff = min(mindiff,abs((sum-i)-i));
             }
        }

        
       
        return mindiff;
    }
};