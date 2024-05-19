#include<bits/stdc++.h> 
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int i,vector<int>& nums,vector<int>t,int sum,int target, vector<vector<int>> &ans){
          //as u stay at the same indeex during the take case u will need to check for the sum overbound condition
          if(sum>target){
            return;
          }
          
           if(i==nums.size()){
              if(sum==target){
                 ans.push_back(t);
              }
          
              return;
           }


           t.push_back(nums[i]);
           sum+=nums[i];
           //as u can use the sam element multiple times you will have to stay at that particular index
           solve(i,nums,t,sum,target,ans);

           t.pop_back();
           sum-=nums[i];
           solve(i+1,nums,t,sum,target,ans);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int> >ans;
        vector<int> t;
        int sum=0;
        solve(0,nums,t,sum,target,ans);
        return ans;
    }
};