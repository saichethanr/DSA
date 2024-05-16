#include<bits/stdc++.h> 
using namespace std;
//handle the bounds i>0 and j>0
// Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

// Note: You can only move either down or right at any point in time.
    int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& a){
         if(i==0 && j==0){
            return a[0][0];
         }
         if(i<0 || j<0){
            return INT_MAX;
         }

         if(dp[i][j]!=-1){
            return dp[i][j];
         }
        
        int up = (i > 0) ? solve(i - 1, j, dp, a) + a[i][j] : INT_MAX;
        int left = (j > 0) ? solve(i, j - 1, dp, a) + a[i][j] : INT_MAX;

         dp[i][j] = min(up,left);
         return dp[i][j];
    }

    int minSumPath(int n, int m, vector<vector<int>> &matrix) {
        vector<vector<int>> dp(n, vector<int>(m, 0)); // Initialize a DP table to store minimum path sums

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0)
                    dp[i][j] = matrix[i][j]; // If we are at the top-left corner, the minimum path sum is the value at (0, 0)
                else {
                    // Calculate the minimum path sum considering moving up and moving left
                    int up = matrix[i][j];
                    if (i > 0)
                        up += dp[i - 1][j]; // Include the minimum path sum from above
                    else
                        up = INT_MAX; // A large value if moving up is not possible (out of bounds)

                    int left = matrix[i][j];
                    if (j > 0)
                        left += dp[i][j - 1]; // Include the minimum path sum from the left
                    else
                        left =INT_MAX; // A large value if moving left is not possible (out of bounds)

                    // Store the minimum path sum in dp[i][j]
                    dp[i][j] = min(up, left);
                }
            }
    }