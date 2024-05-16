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
    //we are comming from bottom to top  as the last row itself is the base case
    for(int i=n-2;i>=0;i--){
        for(int j=i;j>=0;j--){
            int down = a[i][j] + dp[i+1][j];
            int dia = a[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down,dia);
        }
    }
    return dp[0][0];
}


/*as u are needing only the next row instead of keeping a whole triangle just keep the next row(front)
  compute the current(curr) row and then now the current row becomes the next row curr = next
*/ 
int solve_spaceopti(vector<vector<int>> &triangle, int n) {
    // Create two arrays to store the current and previous row values
    vector<int> front(n, 0); // Represents the previous row
    vector<int> cur(n, 0);   // Represents the current row
    
    // Initialize the front array with values from the last row of the triangle
    for (int j = 0; j < n; j++) {
        front[j] = triangle[n - 1][j];
    }
    
    // Iterate through the triangle rows in reverse order
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i; j >= 0; j--) {
            // Calculate the minimum path sum for the current cell
            int down = triangle[i][j] + front[j];
            int diagonal = triangle[i][j] + front[j + 1];
            
            // Store the minimum of the two possible paths in the current row
            cur[j] = min(down, diagonal);
        }
        // Update the front array with the values from the current row
        front = cur;
    }
    
    // The front array now contains the minimum path sum from the top to the bottom of the triangle
    return front[0];
}