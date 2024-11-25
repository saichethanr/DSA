#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int j=0;j<=n1;j++){
            dp[0][j] =0;
        }
        for(int i=0;i<=n2;i++){
            dp[i][0] =0;
        }
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }
            }
        }

        int len = dp[n1][n2];
        // constructing the string after finding the longest common subsequence
        string ans = "";
     
        int i=n1;
        int j=n2;
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                ans+=s1[i-1];
                i=i-1;
                j=j-1;
            }
            else if(dp[i-1][j] > dp[i][j-1]){
                ans+=s1[i-1];
                i=i-1;
            }
            else{
                ans+=s2[j-1];
                j=j-1;
            }
        }

        while(i>0){
            ans+=s1[i-1];
            i--;
        }

        while(j>0){
            ans+=s2[j-1];
            j--;
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};