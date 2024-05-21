#include<bits/stdc++.h> 
#include <string>

//76 cases passed
class Solution {
public:
//concatination of all the substring mucst for the orifin nalstring
 void subarray(int ind, string s,string &t,unordered_map<string,int> &mpp){
        if (ind == s.size()) {
            return;
        }  

        t+=s[ind];
        if(mpp.find(t)!=mpp.end()){
            subarray(ind+1,s,t,mpp);
        }
        else{
            mpp[t]++;
            t.clear();
            subarray(ind+1,s,t,mpp);
        }
        
}
    int maxUniqueSplit(string s) {
        string t = "";
        unordered_map<string,int> mpp;
        subarray(0,s,t,mpp);
        return mpp.size();
    }
};




//everything passed
class Solution {
public:
//concatination of all the substring mucst for the orifin nalstring
 int subarray(int ind,string s,string t,unordered_map<string,int> &mpp){
        if (ind == s.size()) {
            return 0;
        }  

        t+=s[ind];
        int take=-1;
        int donttake =-1;
        if(mpp.find(t)==mpp.end()){
            mpp[t]++;
            take = 1 + subarray(ind+1,s,"",mpp);
            mpp.erase(t);
        }
        
        donttake = subarray(ind+1,s,t,mpp);
        return max(take,donttake);
        
}
    int maxUniqueSplit(string s) {
  
        string t = "";
        unordered_map<string,int> mpp;
        return subarray(0,s,t,mpp);
        
    }
};