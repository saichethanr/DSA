     #include<bits/stdc++.h> 
using namespace std;

    // longest palidromic subsequence of a string can be found out but 
    // finding the longest common subsequence between the string and the reverese of the string 
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(),s.end());
        string s2 = s;
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        for(int j=0;j<=n2;j++){
            dp[0][j] =0;
        }
        for(int i=0;i<=n1;i++){
            dp[i][0]=0;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n1][n2];
    }