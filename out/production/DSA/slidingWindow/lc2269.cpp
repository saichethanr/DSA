#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int l=0;
        int r=0;
        int cnt=0;
        int n = s.size();
        string t = "";
        while(r<n){
            t+=s[r];
            
            if((r-l+1)==k){
                if(stoi(t)!=0 && num%stoi(t)==0){
                    cnt++;
                }
                t=t.substr(1);
                l++;
            }
            r++;
        }
        return cnt;
    }
};