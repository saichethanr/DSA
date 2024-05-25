//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(int i,int j,vector<vector<int>> &m,string t,vector<vector<int>>&vis, vector<string>&ans){
               int n = m[0].size();
        //once you reach the destination add return 
        if(i==n-1 && j==n-1){
            ans.push_back(t);
            return;
        }
        
        //for moving down we need to check for the row index
        //visit the current index and unvisit the current index
        if(i+1<n && !vis[i+1][j]&& m[i+1][j]==1){
            vis[i][j]=1;
            solve(i+1,j,m,t+'D',vis,ans);
            vis[i][j]=0;
        }
        
        //for moving left we need to check for the column indexing if we can we should move
        //and mark the visited for the current index
        if(j-1>=0 && !vis[i][j-1] && m[i][j-1]==1){
            vis[i][j]=1;
            solve(i,j-1,m,t+'L',vis,ans);
            vis[i][j]=0;
        }
          //for moving right we need to check for the column indexing if we can we should move
        //and mark the visited for the current index
         if(j+1<n && !vis[i][j+1] && m[i][j+1]==1){
            vis[i][j]=1;
            solve(i,j+1,m,t+'R',vis,ans);
            vis[i][j]=0;
        }
        //for moving down we need to check for the row index
        //visit the current index and unvisit the current index
         if(i-1>=0 && !vis[i-1][j] && m[i-1][j]==1){
            vis[i][j]=1;
            solve(i-1,j,m,t+'U',vis,ans);
            vis[i][j]=0;
        }
        
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<int>>vis(n,vector<int>(n,0));
        vector<string>ans;
        string temp="";
        if(m[0][0]==1){
             solve(0,0,m,temp,vis,ans);
        }
        
        return ans;
    }
};
