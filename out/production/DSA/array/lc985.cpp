#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int findevsum(vector <int> &nums){
        int n = nums.size();
        int sum =0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                sum+=nums[i];
            }
           
        }
        return sum;
    }
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector <int> ans;
        for(int i=0;i<queries.size();i++){
            nums[queries[i][1]] = nums[queries[i][1]] + queries[i][0];
            int ev = findevsum(nums);
            ans.push_back(ev);
        }
        return ans;
    }
};