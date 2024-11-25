#include <vector>
#include<bits/stdc++.h> 
using namespace std;  

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int r=0;
        int l=0;
        int n=nums.size();
        int num1=0;
        int num0=0;
        int maxlen=INT_MIN;
        while(r<n){
           if(nums[r]==0){
            num0++;
           }

           while(num0>1){
              if(nums[l]==0){
                num0--;
              }
              l++;
           }
        maxlen = max(maxlen,(r-l+1));
        r++;
        }
        return maxlen-1;
    }
};