#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int possible(int m,vector<int>& nums){
        int cnt=0;
          for(int i=0;i<nums.size();i++){
              if(nums[i]>=m){
                  cnt++;
              }
          }
          return cnt;
    }
    int specialArray(vector<int>& nums) {
        int maxi=INT_MIN;
        int h;
        int l;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        h=maxi;
        l=0;
        while(l<=h){
            int m=(l+h)/2;
            if(possible(m,nums)==m){
                return m;
            }
            else if(possible(m,nums)<m){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return -1;
    }
};