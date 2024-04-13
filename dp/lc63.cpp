 #include<bits/stdc++.h> 
 #include <vector>
using namespace std;

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