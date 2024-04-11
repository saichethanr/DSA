#include<bits/stdc++.h> 
using namespace std;


    long long maximumSubarraySum_brute(vector<int>& nums, int k) {
        int l=0;
        int n= nums.size();
        int r=k-1;
        
        int maxsum = INT_MIN;
        while(r<n){
           int sum =0;
           unordered_map <int,int> mpp;
           for(int i=l;i<=r;i++){
             sum+=nums[i];
             mpp[nums[i]]++;
           }
           if(mpp.size()==k){
             maxsum = max(sum,maxsum);
           }
           r++;
           l++;
        }
        if(maxsum==INT_MIN){
            return 0;
        }
        return maxsum;
    }

 long long maximumSubarraySum_final(vector<int>& nums, int k) {
        int l=0;
        int n= nums.size();
        int r=k-1;
        
        int maxsum = INT_MIN;
        while(r<n){
           int sum =0;
           unordered_map <int,int> mpp;
           for(int i=l;i<=r;i++){
             sum+=nums[i];
             mpp[nums[i]]++;
           }
           if(mpp.size()==k){
             maxsum = max(sum,maxsum);
           }
           r++;
           l++;
        }
        if(maxsum==INT_MIN){
            return 0;
        }
        return maxsum;
    }
