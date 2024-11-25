#include <bits/stdc++.h> 
using namespace std;

int solve_rec(int idx,int wt,vector<int>&weight,vector<int>&val){
    if(idx==0){
        if(weight[0]<=wt){
           return val[0];
        }
        else{
            return 0;
        }
    }
    int nopick = solve_rec(idx-1,wt,weight,val);
    int pick = INT_MIN;
    if(wt>=weight[idx]){
        pick  = val[idx] + solve_rec(idx-1,wt-weight[idx],weight,val);
    }

    return max(pick,nopick);
}

int solve_memo(int idx,int wt,int weight[],int  val[],vector<vector<int>>&dp){
        if(idx==0){
            if(weight[0]<=wt){
               return val[0];
            }
            else{
                return 0;
            }
        }
       
         if(dp[idx][wt]!=-1){
             return dp[idx][wt];
         }
        
        int nopick = solve_memo(idx-1,wt,weight,val,dp);
        int pick = INT_MIN;
        if(wt>=weight[idx]){
            pick  = val[idx] + solve_memo(idx-1,wt-weight[idx],weight,val,dp);
        }
    
        dp[idx][wt] = max(pick,nopick);
        return dp[idx][wt];
    }

    int solve_tab(int wt,int n,int weight[],int  val[]){

        vector<vector<int>>dp(n,vector<int>(wt+1,-1));
        for(int i=weight[0];i<=wt;i++){
                dp[0][i] = val[0];
        }
       
        for(int i=1;i<n;i++){
            for(int j=0;j<=wt;j++){
                int nopick = dp[i-1][j];
                int pick = INT_MIN;
                if(wt>=weight[i]){
                    pick  = val[i] + dp[i-1][j-weight[i]];
                }
              dp[i][wt] = max(pick,nopick);
            }
        }
    
        return dp[n-1][wt];
    }