 #include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int solve(int i,int j,string s,string t,vector<vector<int>>&dp){
        //string to be matched exausted count
        if(j<0){
            return 1;
        }

        //main string is exausted so dont count
        if(i<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s[i]==t[j]){
             dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
             return dp[i][j];
        }
        else{
            dp[i][j] = solve(i-1,j,s,t,dp);
            return dp[i][j];
        }
    }


};