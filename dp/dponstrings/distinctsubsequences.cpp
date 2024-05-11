 #include<bits/stdc++.h> 
using namespace std;



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


        int solve(string s,string t){
        int n1 = s.size();
        int n2 = t.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
      
        // base case
        for(int i=0;i<=n1;i++){
            dp[i][0] = 1;
        }
        // as we have already written for 0 0 we dont need to overwidte it so start from j=1 
        for(int j=1;j<=n2;j++){
            dp[0][j] =0;
        }


        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
      return dp[n1][n2];

       
    }
