#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int solve(int i,string s,set<string>& wordDict){
        if(i==s.size()){
            return 1;
        }

        string temp = "";
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(solve(j+1,s,wordDict)){
                    return 1;
                }

            }
        }
        return 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        return solve(0,s,st);
    }
};


class Solution {
public:
    int solve(int i,string s,set<string>& wordDict,vector<int> &dp){
        if(i==s.size()){
            return 1;
        }
        
        string temp = "";
         if(dp[i]!=-1){
            return dp[i];
         }
        for(int j=i;j<s.size();j++){
            temp+=s[j];
            if(wordDict.find(temp)!=wordDict.end()){
                if(solve(j+1,s,wordDict,dp)){
                    dp[i] = 1;
                    return dp[i];
                }

            }
        }
        dp[i] =0;
        return dp[i];
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        vector<int>dp(301,-1);
        for(int i=0;i<wordDict.size();i++){
            st.insert(wordDict[i]);
        }
        return solve(0,s,st,dp);
    }
};