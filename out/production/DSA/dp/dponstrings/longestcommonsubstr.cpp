 #include<bits/stdc++.h> 
using namespace std;

    // similar to the longest common subsequence but there we used to conisder all the cases even 
    // though if the characters wouldnt match but if the character wooudnt match we will break
    // the chain and do a fresh begining
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        for(int j=0;j<=m;j++){
            dp[0][j] =0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        
        int len = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    len = max(dp[i][j],len);
                }
                else{
                    dp[i][j]=0;
                }
            }
        }
        return len;
    }