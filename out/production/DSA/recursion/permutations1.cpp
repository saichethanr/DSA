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




class Solution {
public:
    //on each iteration of the recursion try pushing the ds into the matrix and then return the matrix at the end
    void solve(vector<int>& nums,vector<int>t,vector<bool>freq,vector<vector<int>>&ans){
        //once the taken datastructure size becomes equal to that of the given array
        //then we have to return
         if(t.size()==nums.size()){
            ans.push_back(t);
            return;
         }
         //why are we loooping 
         //for each index in the freq map we are checking for it availability in each of the recursive call
         for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=true;
                t.push_back(nums[i]);
                solve(nums,t,freq,ans);
                freq[i]=false;
                t.pop_back();
            }
         }

    }
    vector<vector<int>> permute(vector<int>& nums) {
       int n=nums.size();
        vector<bool>freq(n);
        vector<int>t;
        vector<vector<int>>ans;
        solve(nums,t,freq,ans);
        return ans;
    }
};