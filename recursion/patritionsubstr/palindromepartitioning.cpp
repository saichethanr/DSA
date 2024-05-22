#include<bits/stdc++.h> 
#include <string>
using namespace std;


//initial approach and this is not giving me the correct answer
class Solution {
public:
    void solve(int ind,vector<string>t,string s,string temp,vector<vector<string>>&ans){
        if(ind==s.size()){
            ans.push_back(t);
            return;
        }
        temp+=s[ind];
        string rev = temp;
        reverse(rev.begin(),rev.end()); 
        if(rev==temp){
            t.push_back(temp);
            solve(ind+1,t,s,"",ans);
            t.pop_back();
        }

       solve(ind+1,t,s,temp,ans);
    }
    vector<vector<string>> partition(string s) {
     vector<vector<string>> ans;
     vector<string>t;
     string temp="";
     solve(0,t,s,temp,ans);
     return ans;
    }
};



class Solution {
public:
    void solve(int ind,vector<string>t,string s,vector<vector<string>>&ans){
        if(ind==s.size()){
            ans.push_back(t);
            return;
        }
        for(int i=ind;i<s.size();i++){
            if(ispalindrome(s,ind,i)){
                t.push_back(s.substr(ind,i-ind+1));
                solve(i+1,t,s,ans);
                t.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }

        return true;
    }
    vector<vector<string>> partition(string s) {
     vector<vector<string>> ans;
     vector<string>t;
     string temp="";
     solve(0,t,s,ans);
     return ans;
    }
};