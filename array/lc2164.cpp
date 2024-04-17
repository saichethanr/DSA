#include<bits/stdc++.h> 
using namespace std;

// You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:

// Sort the values at odd indices of nums in non-increasing order.
// For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 1 and 3 are sorted in non-increasing order.
// Sort the values at even indices of nums in non-decreasing order.
// For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 0 and 2 are sorted in non-decreasing order.
// Return the array formed after rearranging the values of nums.



vector<int> sortEvenOdd(vector<int>& nums) {
        vector <int> ans(nums.size(),0);
        priority_queue <int> pq1;
        priority_queue <int,vector<int>,greater<int>> pq2;
        for(int i=1;i<nums.size();i+=2){
            pq1.push(nums[i]);
        }
        int i=1;
        while(!pq1.empty() &&  i<nums.size()){
             ans[i] = pq1.top();
             pq1.pop();
             i+=2;
        }
         for(int i=0;i<nums.size();i+=2){
            pq2.push(nums[i]);
        }

        i=0;
          while(!pq2.empty() &&  i<nums.size()){
             ans[i] = pq2.top();
             pq2.pop();
             i+=2;
        }
      
       
      
      
      return ans;
        
    }