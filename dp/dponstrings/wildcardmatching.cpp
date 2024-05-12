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