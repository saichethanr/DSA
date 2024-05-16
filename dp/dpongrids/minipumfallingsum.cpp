#include<bits/stdc++.h> 
using namespace std;

// Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
// A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. 
// Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).
 int solve_recursion(int i,int j,vector<vector<int>>& matrix){
        int n = matrix[0].size();
         if(j<0 || j>=n){
            return INT_MAX;
        }
        if(i==0){
            return matrix[0][j];
        }
        //explore all the paths
        
        int  up = solve_recursion(i - 1, j, matrix);
        if(up!=INT_MAX){
            up+=matrix[i][j];
        }
        int  ld = solve_recursion(i - 1, j - 1, matrix);
        if(ld!=INT_MAX){
            ld+=matrix[i][j];
        }
        int rd = solve_recursion(i - 1, j + 1, matrix);
        if(rd!=INT_MAX){
            rd+=matrix[i][j];
        }

        return min(up, min(ld, rd));

    }

    int solve_memoization(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n = matrix[0].size();
         if(j<0 || j>=n){
            return INT_MAX;
        }
        if(i==0){
            return matrix[0][j];
        }
        //explore all the paths
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        int  up = solve_memoization(i - 1, j, matrix,dp);
        if(up!=INT_MAX){
            up+=matrix[i][j];
        }
        int  ld = solve_memoization(i - 1, j - 1, matrix,dp);
        if(ld!=INT_MAX){
            ld+=matrix[i][j];
        }
        int rd = solve_memoization(i - 1, j + 1, matrix,dp);
        if(rd!=INT_MAX){
            rd+=matrix[i][j];
        }
        
        dp[i][j] = min(up, min(ld, rd));
        return dp[i][j];

    }

        int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix[0].size();
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        
        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
            int up = dp[i - 1][j];
            int ld = (j - 1 >= 0) ? dp[i - 1][j - 1]: INT_MAX;
            int rd = (j + 1 < m) ? dp[i - 1][j + 1] : INT_MAX;
            dp[i][j] = matrix[i][j] + min(up, min(ld, rd));
            }
        }

        //answers are stored in the last row of the dp 
        //the minimum of those answers have to be returned
        int mini = INT_MAX;
        for(int i=0;i<m;i++){
          mini = min(mini,dp[n-1][i]);
        }

        return mini;
        
    }