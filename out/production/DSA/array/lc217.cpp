  #include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       set <int> st;
       for(int i=0;i<nums.size();i++){
        st.insert(nums[i]);
       } 

       if(st.size()==nums.size()){
         return false;
       }
       return true;
    }
};