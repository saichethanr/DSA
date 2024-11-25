#include<bits/stdc++.h> 
using namespace std;
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