#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        long long int numop =0;
        int mid =nums.size()/2;
        if(nums[mid]==k){
            return 0;
        }
        else{
            if(nums[mid]>k){
                numop += (nums[mid]-k);
                nums[mid] =k;
                for(int i=mid;i>0;i--){
                    if(nums[i-1]>nums[i]){
                        numop+=(nums[i-1]-nums[i]);
                        nums[i-1]=nums[i];
                    }
                }
            }
            else if(nums[mid]<k){
                numop+=(k-nums[mid]);
                nums[mid]=k;
                for(int i=mid;i<nums.size()-1;i++){
                    if(nums[i]>nums[i+1]){
                         numop+=(nums[i]-nums[i+1]);
                         nums[i+1]=nums[i];
                    }
                }
            }
        }
        return numop;
    }
};