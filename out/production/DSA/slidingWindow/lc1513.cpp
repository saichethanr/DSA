#include <vector>
#include<bits/stdc++.h> 
using namespace std;  

// Given a binary string s, return the number of substrings with all characters 1's.
//  Since the answer may be too large, return it modulo 109 + 7.


 int numSub(string s) {
        int l=0;
        int r=0;
        long long  cnt=0;
        int n = s.size();
        int mod = 1e9 + 7;
        while(r<n){
            if(s[r]=='0'){
                r++;
                l=r;
            }
            else{
                cnt+=(r-l+1);
                r++;
            }
        }

        return cnt%mod;
    }