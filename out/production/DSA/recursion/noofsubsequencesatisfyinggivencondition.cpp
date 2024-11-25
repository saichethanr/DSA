#include<bits/stdc++.h> 
#include <vector>
using namespace std;

//condition :  maxelement(subsequence) + min(subsequence) <= target

//approach 1

class Solution {
public:
    void solve(int i,vector<int> nums,vector<int>t,vector<vector<int>> &ans){
        if(i==nums.size()){
             if (!t.empty()) {  
                ans.push_back(t);
            }
            return;
        }

        t.push_back(nums[i]);
        solve(i+1,nums,t,ans);
        t.pop_back();

        solve(i+1,nums,t,ans);
    }
    int numSubseq(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> t;
        solve(0,nums,t,ans);
        int cnt=0;
        for(int i=0;i<ans.size();i++){
             auto max_it = max_element(ans[i].begin(), ans[i].end());
             auto min_it = min_element(ans[i].begin(), ans[i].end());
             if((*max_it + *min_it)<=target){
                cnt++;
             }

        }
        return cnt;
    }
};