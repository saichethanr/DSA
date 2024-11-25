 #include<bits/stdc++.h> 
 #include <vector>
using namespace std;

// You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

// An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

// Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

// The testcases are generated so that the answer will be less than or equal to 2 * 109.



 int solve(int i,int j,vector<vector<int>>&dp,vector<vector<int>>& obstacleGrid){
          if(i==0&&j==0){
            return obstacleGrid[i][j]==0?1:0;
          }
          if(i<0 || j<0){
            return 0;
          } 
          if(obstacleGrid[i][j]==1){
            return 0;
          }
          if(dp[i][j]!=-1){
            return dp[i][j];
          }

          int up = solve(i-1,j,dp,obstacleGrid);
          int left = solve(i,j-1,dp,obstacleGrid);

          dp[i][j] = up+left;
          return dp[i][j];
    }