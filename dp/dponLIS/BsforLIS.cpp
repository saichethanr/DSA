#include<bits/stdc++.h> 
using namespace std;

//using the lower bound approach needs revisiion
int solve(vector<int> nums){
        int n = nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);

        for(int i=0;i<nums.size();i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return temp.size();
}