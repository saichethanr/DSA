#include<bits/stdc++.h> 
using namespace std;

int solve_rec(int i,int j,int n,vector<vector<int>>& a){
            if(i==n-1){
                return a[n-1][j];
            }

            int down = a[i][j] + solve_rec(i+1,j,n,a);
            int dia = a[i][j] + solve_rec(i+1,j+1,n,a);
          return min(down,dia);
}

int solve_memoization(int i,int j,int n,vector<vector<int>>& a,vector<vector<int>>& dp){
            if(i==n-1){
                return a[n-1][j];
            }
            
            if(dp[i][j]!=-1){
                return dp[i][j];
            }
            int down = a[i][j] + solve_memoization(i+1,j,n,a,dp);
            int dia = a[i][j] + solve_memoization(i+1,j+1,n,a,dp);
            dp[i][j] = min(down,dia);
            return dp[i][j];
    }

int solve_tabulation(int n,vector<vector<int>>& a,vector<vector<int>>& dp){

    //beacause the base case exist at row n-1 first wehva eto deifne the base case 
    for(int k=0;k<n;k++){
        dp[n-1][k] = a[n-1][k];
    }           
    //as computaion for n-1 is done start from n-2;
    //
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = a[i][j] + dp[i+1][j];
            int dia = a[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,dia);
        }
    }
    return dp[0][0];
}