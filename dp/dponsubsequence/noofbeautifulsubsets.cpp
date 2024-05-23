#include <bits/stdc++.h> 
using namespace std;

// You are given an array nums of positive integers and a positive integer k.
// A subset of nums is beautiful if it does not contain two integers with an absolute difference equal to k.
// Return the number of non-empty beautiful subsets of the array nums.
// A subset of nums is an array that can be obtained by deleting some (possibly none) elements from nums.
//  Two subsets are different if and only if the chosen indices to delete are different.



class Solution {
public:
    int solve(int ind,vector<int> &nums,int k,vector<int> &t){
          if(ind==nums.size()){
            bool check = true;
            for(int i=0;i<t.size();i++){
                for(int j=i;j<t.size();j++){
                    if(abs(t[i]-t[j])==k){
                        check = false;
                        break;
                    }
                }
                if(!check){
                    break;
                }
            }
              if(check){
                return 1;
              }
              return 0;
          }
          //take case

          t.push_back(nums[ind]);
          int take = solve(ind+1,nums,k,t);
          t.pop_back();

          //notake case
          int notake = solve(ind+1,nums,k,t);
          return take+notake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>t;
        int n = nums.size();
        return solve(0,nums,k,t)-1;
    }
};