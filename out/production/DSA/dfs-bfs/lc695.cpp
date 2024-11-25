#include<bits/stdc++.h> 
using namespace std;


// You are given an m x n binary matrix grid. An island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

// The area of an island is the number of cells with a value 1 in the island.

// Return the maximum area of an island in grid. If there is no island, return 0.


class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& grid,int &cnt){
        int m = grid.size();
        int n = grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return;
        }

        cnt++;

        grid[i][j]=0;

        dfs(i-1,j,grid,cnt);
        dfs(i+1,j,grid,cnt);
        dfs(i,j-1,grid,cnt);
        dfs(i,j+1,grid,cnt);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt=0;
        int maxarea = INT_MIN;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cnt=0;
                if(grid[i][j]==1){
                    dfs(i,j,grid,cnt);
                    maxarea = max(maxarea,cnt);
                }
            }
        }
        if(maxarea==INT_MIN){
            return 0;
        }
    return maxarea;
    }
};