#include<bits/stdc++.h> 
using namespace std;

    int countGoodSubstrings(string s) {
        int l=0;
        int r=0;
        int n=s.size();
        int cnt=0;
        unordered_map<int,int>mpp;
        while(r<n){
             mpp[s[r]]++;
             if((r-l+1)==3){
                if(mpp.size()==3){
                    cnt++;
                }
                mpp[s[l]]--;
                if(mpp[s[l]]==0){
                    mpp.erase(s[l]);
                }
                l++;
             }
             r++;
        }
        return cnt;
    }