#include<bits/stdc++.h> 
using namespace std;

//you have to return all those subsets which are unique only and that s done by sorting a subset and storing it in a 
//set and then extracting elements from the set
class Solution {
public:
     void solve(int i,vector<int>& nums,vector<int>t, set<vector<int>> &st){
      
           if(i==nums.size()){
                 sort(t.begin(),t.end());
                 st.insert(t);
                 return;
           }

           //take case
           t.push_back(nums[i]);
           solve(i+1,nums,t,st);

           //no take case
           t.pop_back();    
           solve(i+1,nums,t,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int> t;
        set<vector<int>>st;
        solve(0,nums,t,st);
        for (set<vector<int>>::iterator it = st.begin(); it != st.end(); ++it) {
              ans.push_back(*it);
        }
        return ans;
    }
};
