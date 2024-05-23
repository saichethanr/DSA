// Given a boolean expression s of length n with following symbols.
// Symbols
//     'T' ---> true
//     'F' ---> false
// and following operators filled between symbols
// Operators
//     &   ---> boolean AND
//     |   ---> boolean OR
//     ^   ---> boolean XOR
// Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true.

// Note: The answer can be large, so return it with modulo 1003

// User function Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;



class Solution{
public:
   int mod = 1003;
    int solve(int i, int j, int isTrue, string& S,vector<vector<vector<long long>>>& dp) {
        if(i>j) return 0;
        if(i==j) {
            if(isTrue) {
                return S[i]=='T';
            }
            else {
                return S[i]=='F';
            }
        }
        if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];
        int ways=0;
        for(long long ind=i+1;ind<=j-1;ind=ind+2) {
            long long lT = solve(i,ind-1,1,S,dp);
            long long lF = solve(i,ind-1,0,S,dp);
            long long rT = solve(ind+1,j,1,S,dp);
            long long rF = solve(ind+1,j,0,S,dp);
            
            if(S[ind]== '&') {
                if(isTrue) ways = (ways + (lT*rT)%mod)%mod;
                else ways = (ways + (lT*rF)%mod + (lF*rT)%mod + (lF*rF)%mod)%mod;
            }
            else if(S[ind]== '|') {
                if(isTrue) ways = (ways + (lT*rT)%mod + (lT*rF)%mod + (lF*rT)%mod)%mod;
                else ways = (ways + (lF*rF)%mod)%mod;
            }
            else {
                if(isTrue) ways = (ways + (lT*rF)%mod + (lF*rT)%mod) % mod;
                else  ways = (ways + (lT*rT)%mod + (lF*rF)%mod);
            }
        }
        return dp[i][j][isTrue] = ways;
    }
    int countWays(int N, string S){
        vector<vector<vector<long long>>>dp(N,vector<vector<long long>>(N,vector<long long>(2,-1)));
        return solve(0,N-1,1,S,dp);
    }
};