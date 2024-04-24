#include <bits/stdc++.h> 
using namespace std;

int solve(int idx,vector <int> &nums,int target){
     if(target==0){
        return 1;
     }
     if(idx==0){
        return (nums[idx]==target);
     }

    int nopick = solve(idx-1,nums,target);
    int pick =0;
    if(target>=nums[idx]){
        pick = solve(idx-1,nums,target-nums[idx]);
    }

    return nopick + pick;
}

int solve_memo(int idx,vector <int> &nums,int target,vector<vector<int>>&dp){
     if(idx==0){
        if(target==0 && nums[0]==0){
            return 2;
        }
        if(target==0 || nums[idx]==target){
            return 1;
        }
        return 0;
     }
    
	if(dp[idx][target]!=-1){
		return dp[idx][target];
	}
    int nopick = solve_memo(idx-1,nums,target,dp);
    int pick =0;
    if(target>=nums[idx]){
        pick = solve_memo(idx-1,nums,target-nums[idx],dp);
    }

	dp[idx][target] = nopick + pick;

    return dp[idx][target];
}

int solve_tab(int idx,vector <int> &arr,int k,vector<vector<int>>&dp){
    int n = arr.size();
   vector<vector<int>>dp(n,vector<int>(k+1,0));
   for(int i=0;i<n;i++){
       dp[i][0] = 1;
   }
   
   if(arr[0]<=k){
          dp[0][arr[0]] = 1;
   }


   for(int i=1;i<n;i++){
       for(int j=0;j<=k;j++){
           int nopick = dp[i-1][j];
           int pick =0;
           if(j>=arr[i]){
               pick = dp[i-1][j-arr[i]];
           }
           dp[i][j] = pick + nopick;
       }
   }
 
   return dp[n-1][k];
}