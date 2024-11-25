 #include<bits/stdc++.h> 
using namespace std;


// if we want to calculate the minimum insertion to make the string palindrome 
// first we need to keep the  longest palindromic part of the string intact and the we have to duuplicate the
// non palindromic part of the string
// the duplicated string is counted as the min operations

class Solution {
public:
    int minInsertions(string s) {
        string s1 =s;
        string s2;
        reverse(s.begin(),s.end());
        s2 = s;

        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=0;j<=m;j++){
            dp[0][j] =0;
        }
        for(int i=0;i<=m;i++){
            dp[i][0] =0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return s.size()-dp[n][m];
    }
};