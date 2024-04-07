#include<bits/stdc++.h> 
using namespace std;
// Given a binary array nums and an integer goal, return the number of non-empty subarrays with a sum goal.

// A subarray is a contiguous part of the array.


class Solution {
public:

    int numSubarraysWithSum(vector<int>& nums, int goal) {
         unordered_map<int,int> mpp;
       int presum = 0;
       mpp[presum]++;
       int cnt=0;
       for(int i=0;i<nums.size();i++){
          presum+=nums[i];
          if(mpp.find(presum-goal)!=mpp.end()){
            cnt+=mpp[presum-goal];
          }
          mpp[presum]++;
       }
       return cnt;
    }
};