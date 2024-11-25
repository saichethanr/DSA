#include<bits/stdc++.h> 
#include <string>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>mpp;
        if(s.size()==1){
            return 1;
        }
        for(int i=0;i<s.size();i++){
            mpp[s[i]]++;
        }

        if(mpp.size()==1){
            for(auto it : mpp){
                return it.second;
            }
        }
        bool flag=false;
        int len=0;
        for(auto it : mpp){
           if(it.second%2==0){
                len +=it.second;
           }
           else{
              len+=it.second-1;
              flag = true;
           }
        }

        if(flag){
            len+=1;
        }
        return len;
    }
};