#include<bits/stdc++.h> 
using namespace std;
class Solution
{ 
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n,int k){
        //if there is one floor attemps=1 0 foloor attempt ==0
        if(k==1 || k==0){
            return k;
        }
        
        //if there is a single egg then the no of attempts needed is the number of floors
        if(n==1){
            return k;
        }
        
        int mini = INT_MAX;
        int res;
        int x;
        for(int x=1;n<=k;x++){
            res = max(solve(n-1,k-1),solve(n,k-x));
            if(res<mini){
                mini = res;
            }
        }
        return mini+1;
        
    }
    int eggDrop(int n, int k) 
    {
        return solve(n,k);
    }
};



class Solution
{ 
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n,int k){
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        int mini = INT_MAX;
        int res;
        int x;
      
        
        
        for(int i=1;i<=n;i++){
            dp[i][1] = 1;
            dp[i][0] = 0;
        }
        
        for(int i=1;i<=k;i++){
            dp[1][i] = i;
        }
        
        for(int i=2;i<=n;i++){
            for(int j=2;j<=k;j++){
                dp[i][j] =INT_MAX;
                  for(int x=1;n<=k;x++){
                      
                        res = max(dp[i-1][j-1],dp[i][j-x]);
                            if(res<dp[i][j]){
                                dp[i][j] = res;
                            }
                }
                
                
        
            }
        }
        
        return dp[n][k];
        
    }
    int eggDrop(int n, int k) 
    {
        return solve(n,k);
    }
};