#include<bits/stdc++.h> 
using namespace std;


// Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.

// A subarray is a contiguous non-empty sequence of elements within an array.


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int> mpp;
       int presum = 0;
       mpp[presum]++;
       int cnt=0;
       for(int i=0;i<nums.size();i++){
          presum+=nums[i];
          if(mpp.find(presum-k)!=mpp.end()){
            cnt+=mpp[presum-k];
          }
          mpp[presum]++;
       }
       return cnt;
    }
};