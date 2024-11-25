#include<bits/stdc++.h> 
#include <vector>
using namespace std;


class Solution {
public:
// this returend a memory limit exeeded error 
// we have to use set because every valid subsequence should be returnred lexograpphically and it should be unique subsequence
    void solve(int i,vector<int>& nums,vector<int>t,int sum,int target, set<vector<int>> &st){
           if(i==nums.size()){
              if(sum==target){
                 sort(t.begin(),t.end());
                 st.insert(t);
              }
            
              return;
           }
           t.push_back(nums[i]);
           sum+=nums[i];
           solve(i+1,nums,t,sum,target,st);

           t.pop_back();
           sum-=nums[i];
           solve(i+1,nums,t,sum,target,st);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int> >ans;
        vector<int> t;
        set<vector<int>>st;
        int sum=0;
        solve(0,nums,t,sum,target,st);
        for (set<vector<int>>::iterator it = st.begin(); it != st.end(); ++it) {
              ans.push_back(*it);
        }
        return ans;
    }
};