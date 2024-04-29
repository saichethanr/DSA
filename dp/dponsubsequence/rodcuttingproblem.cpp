#include <bits/stdc++.h> 
using namespace std;


int solve(int idx,int n,vector<int> &price,  vector<vector<int>>&dp){
    if(idx==0){
		return (n/(idx+1))*price[idx];
	}
    
	

	int notake = solve(idx-1,n,price,dp);
	int take = INT_MIN;
	if(n>=(idx+1)){
		take = price[idx] + solve(idx,n-(idx+1),price,dp);
	}
	 return max(take,notake);
	
}


int solve(int idx,int n,vector<int> &price,  vector<vector<int>>&dp){
    if(idx==0){
		return (n/(idx+1))*price[idx];
	}
    
	if(dp[idx][n]!=-1){
		return dp[idx][n];
	}

	int notake = solve(idx-1,n,price,dp);
	int take = INT_MIN;
	if(n>=(idx+1)){
		take = price[idx] + solve(idx,n-(idx+1),price,dp);
	}
	dp[idx][n] = max(take,notake);
	return dp[idx][n];
}


int solve(int idx,int n,vector<int> &price,  vector<vector<int>>&dp){
  
    for(int i=0;i<=n;i++){
        dp[0][i] = i*price[0];
    }
    

    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            int notake = dp[i-1][j];
            int take = INT_MIN;
            if(j>=(i+1)){
                take = price[i] + dp[i][j-(i+1)];
            }
	        dp[i][j] = max(take,notake);
        }
    }


	return dp[n-1][n];
}


