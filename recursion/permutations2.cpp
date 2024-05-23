#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    //this is my brute force approch to store all permutations into a set 
    //and then retrive the permutations inot the matrix
    //and then return the matrix
    //as there are duplicated i would want to store the vectors into the set as i have to return uniquee permutations only
    void solve(vector<int>& nums,vector<int>t,vector<bool>freq,set<vector<int>>& st){
         if(t.size()==nums.size()){
            st.insert(t);
            return;
         }
         
         for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                freq[i]=true;
                t.push_back(nums[i]);
                solve(nums,t,freq,st);
                freq[i]=false;
                t.pop_back();
            }
         }

    }

    //this approach uses the same approach of thet of the frequency map 
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        vector<bool>freq(n);
        vector<int>t;
        vector<vector<int>>ans;
        set<vector<int>>st;
        solve(nums,t,freq,st);
        for (set<vector<int>>::iterator it = st.begin(); it != st.end(); ++it) {
            ans.push_back(*it);
        }
        return ans;
    }
};