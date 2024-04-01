#include<bits/stdc++.h> 
using namespace std;

// Given a string s, find the length of the longest 
// substring
//  without repeating characters.

   int myapproach(string s) {
        int l=0;
        int r=0;
        if(s.size()<=1){
            return s.size();
        }
        int cnt=0;
        int maxlen = INT_MIN;
        map <char,int> mpp;
        for(int r=0;r<s.size();r++){
            if(mpp.find(s[r])==mpp.end()){
               mpp[s[r]] =r;
               cnt++;
            }
            else{
              l = mpp[s[r]]+1;
              mpp[s[r]]=r;
              
            }
            maxlen = max(maxlen,r-l+1);
           
        }
        if(cnt==s.size()){
            return cnt;
        }

        return maxlen;
       
    }

int ans(string s) {
        int l = 0;
        int maxlen = 0;
        map<char, int> mpp;
        for (int r = 0; r < s.size(); r++) {
            if (mpp.find(s[r]) == mpp.end() || mpp[s[r]] < l) {  //why this 
                mpp[s[r]] = r;
            } 
            else {
                l = mpp[s[r]] + 1;
                mpp[s[r]] = r;
            }
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
       
    }