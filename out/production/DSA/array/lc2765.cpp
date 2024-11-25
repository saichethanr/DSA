#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    int alternatingSubarray(vector<int>& nums) {
            int ans =0;
            for(int i=0;i<nums.size();i++){
                 int d = 1;
                 int j;
                 for( j=i+1;j<nums.size();j++){
                    if(nums[j]-nums[j-1]!=d){
                        break;
                    }
                    d = (d==1)?-1:1;
                 }
                 ans = max(ans,j-i);
            }
            ans =  (ans>1)?ans:-1;
            return ans;
    }
};