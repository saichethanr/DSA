 #include<bits/stdc++.h> 
using namespace std;


 int solve(int ind1,int ind2,string s1,string s2){
        if(ind1<0 || ind2<0){
            return 0;
        }

        if(s1[ind1]==s2[ind2]){
            return 1 + solve(ind1-1,ind2-1,s1,s2);
        }

        return max(solve(ind1,ind2-1,s1,s2),solve(ind1-1,ind2,s1,s2));
    }

    int solve(int ind1,int ind2,string s1,string s2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0){
            return 0;
        }
        if(dp[ind1][ind2]!=-1){
            return dp[ind1][ind2];
        }
        if(s1[ind1]==s2[ind2]){
            dp[ind1][ind2] = 1 + solve(ind1-1,ind2-1,s1,s2,dp);
            return dp[ind1][ind2];
        }

        dp[ind1][ind2] = max(solve(ind1,ind2-1,s1,s2,dp),solve(ind1-1,ind2,s1,s2,dp));
   
        return dp[ind1][ind2];
    }

       int longestCommonSubsequence(string s1, string s2) {
        int n1  =  s1.size();
        int n2 = s2.size();
         vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
         for(int j=0;j<=n2;j++){
            dp[0][j] = 0;
         }
         for(int i=0;i<=n1;i++){
            dp[i][0] =0;
         }

         for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                   dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }

                
            }
         }
        return dp[n1][n2];
        
    }