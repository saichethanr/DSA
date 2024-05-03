#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxnum = INT_MIN;
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
         if(nums[i]<0){
            mpp[nums[i]]++;
         }
        } 
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                int t = -1*nums[i];
                if(mpp.find(t)!=mpp.end()){
                    maxnum = max(maxnum,nums[i]);
                }
            }
        }
        if(maxnum==INT_MIN){
            return -1;
        }
        return maxnum;
    }
};