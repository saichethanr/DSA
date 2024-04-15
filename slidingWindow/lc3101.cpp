#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int l=0;
        long long ans =0;
        int r=0;
        int prev=-1;
        int n = nums.size();
        while(r<n){
            if(nums[r]==prev){
                l=r;
            }
            ans+=(r-l+1);
            prev = nums[r];
            r++;
        }
        return ans;
    }
};