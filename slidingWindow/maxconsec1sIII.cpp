#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int l=0;
        int numz=0;
        int maxlen = INT_MIN;
        for(int r=0;r<nums.size();r++){
              if(nums[r]==0){
                numz++;
              }

              while(numz>k){
                 if(nums[l]==0){
                    numz--;
                 }
                 l++;
              }

              maxlen = max(maxlen,r-l+1);
            
         }
         return maxlen;

    }
};