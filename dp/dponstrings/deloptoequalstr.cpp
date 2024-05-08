 #include<bits/stdc++.h> 
using namespace std;

// to find the min no of deletions to made to equal the strings we need to keep the longest common subsequence of 
// the two strings in tact and then we need to add up the diffrence between the len of the two strings 
// with the longest common subseqquence 
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<=m;j++){
            dp[0][j] =0;
        }
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int ans = word1.size() - dp[n][m];
        ans+=word2.size() - dp[n][m];

        return ans;
    }
};