#include<bits/stdc++.h> 
using namespace std;    


class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int l=0;
        int r=0;
        int sum=0;
        int maxlen =INT_MIN;
        int n = s.size();
        while(r<n){
            sum+=(abs(s[r]-t[r]));
            while(sum>maxCost){
                sum-=(abs(s[l]-t[l]));
                l++;
            }
            maxlen = max(maxlen,r-l+1);
            r++;
        }
        return maxlen;
    }
};