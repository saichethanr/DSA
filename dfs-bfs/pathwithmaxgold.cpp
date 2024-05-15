#include<bits/stdc++.h> 
using namespace std;


//once after visiting a node and trying all the posible moves on that node we need to make vissited false and 
//so that for the adjacent moves we would need this sum 

class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }
        visited[i][j] = true;
        int top = grid[i][j] + solve(i - 1, j, grid, visited);
        int down = grid[i][j] + solve(i + 1, j, grid, visited);
        int left = grid[i][j] + solve(i, j - 1, grid, visited);
        int right = grid[i][j] + solve(i, j + 1, grid, visited);

        int maxgold = max({top, down, left, right});
        visited[i][j] = false;
        return maxgold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        int maxGold = 0;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != 0) {
                    maxGold = max(maxGold, solve(i, j, grid, visited));
                }
            }
        }

        return maxGold;
    }
};
