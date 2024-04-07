#include<bits/stdc++.h> 
using namespace std;

// Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

// Return the number of nice sub-arrays.

class Solution {
public:
    int solve(vector<int>& nums, int k){
         int l=0;
        int odd=0;
        int cnt=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]%2==1){
                odd++;
            }

            while(l<=r && odd>k){
                if(nums[l]%2==1){
                    odd--;
                }
                l++;
            } 
          cnt+=(r-l+1);
        }
        return cnt;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
      int ans = solve(nums,k) - solve(nums,k-1);
      return ans;
    }
};