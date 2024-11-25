#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        std::cin.tie(0);
        std::cout.tie(0);
        unordered_map <int,int> mpp;
        vector <int> ans;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        while(k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};