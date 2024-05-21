#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> t;
        do { 
            t.clear();
                for (int num : nums) {
                t.push_back(num);
            }
            ans.push_back(t);
        
    } while (next_permutation(nums.begin(), nums.end()));
    return ans;
    }
};