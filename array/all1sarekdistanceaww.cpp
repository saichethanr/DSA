#include <bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int ind =-1;
        bool flag = false;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                if(ind!=-1 && i-ind-1<k){
                    return false;
                }
                ind =i;
            }
        }
        return true;
         
    }
};