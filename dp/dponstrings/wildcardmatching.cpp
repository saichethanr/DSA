#include<bits/stdc++.h> 
using namespace std;

    bool solve(int i,int j,string s,string p){
        //if both are exausted return true
        if(i<0 && j<0){
            return true;
        }
        //if pattern is exausted and the string is left return false as there is no other option
        if(i<0 && j>=0){
            return false;
        }
        
        if(j<0 && i>=0){
            //is the string is empty and the pattern remains
            //then  the pattern should only contain all stars to be able to match to the empty string 
            bool check = true;
            for(int k=i;k>=0;k--){
                if(p[k]!='*'){
                    check = false;
                    break;
                }
            }
            return check;
        }
        //if the pattern contsins ? it can be matched to any char in the string 
        if(p[i]==s[j] || p[i]=='?'){
           return solve(i-1,j-1,s,p);
        }
        //if the pattern contaains * it can be matched to any sequence 
        //hence the * can either be considered as null 
        //or the str can be matched to a character
        if(p[i]=='*'){
            return solve(i-1,j,s,p) | solve(i,j-1,s,p);
        }

        return false;
    }



        bool solve(int i,int j,string s,string p, vector<vector<int>>&dp){
        //if both are exausted return true
        if(i<0 && j<0){
            return true;
        }
        //if pattern is exausted and the string is left return false as there is no other option
        if(i<0 && j>=0){
            return false;
        }
        
        if(j<0 && i>=0){
            //is the string is empty and the pattern remains
            //then  the pattern should only contain all stars to be able to match to the empty string 
            bool check = true;
            for(int k=i;k>=0;k--){
                if(p[k]!='*'){
                    check = false;
                    break;
                }
            }
            return check;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        //if the pattern contsins ? it can be matched to any char in the string 
        if(p[i]==s[j] || p[i]=='?'){
           dp[i][j] = solve(i-1,j-1,s,p,dp);
           return dp[i][j];
        }
        //if the pattern contaains * it can be matched to any sequence 
        //hence the * can either be considered as null 
        //or the str can be matched to a character
        if(p[i]=='*'){
            dp[i][j] = solve(i-1,j,s,p,dp) | solve(i,j-1,s,p,dp);
            return dp[i][j];
        } 

        return false;
    }




    class Solution {
public:
  
    bool isMatch(string s, string p) {
        int n1=p.size();
        int n2 = s.size();
        vector<vector<bool>>dp(n1+1,vector<bool>(n2+1,false));
        dp[0][0] =true;
        for(int j=1;j<=n2;j++){
            dp[0][j] = false;
        }
 
        for(int i=1;i<=n1;i++){
            bool check = true;
            for(int k=1;k<=i;k++){
                if(p[k-1]!='*'){
                    check=false;
                    break;
                }
            }
            dp[i][0] =check;
        }


        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                //if the pattern contsins ? it can be matched to any char in the string 
                if(p[i-1]==s[j-1] || p[i-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[i-1]=='*'){
                    //if the pattern contaains * it can be matched to any sequence 
                //hence the * can either be considered as null 
                //or the str can be matched to a character
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                } 
                else{
                    dp[i][j] = false;
                }
                 
            }
        }
        return dp[n1][n2];
    }
};

