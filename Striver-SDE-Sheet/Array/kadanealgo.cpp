#include<bits/stdc++.h> 
#include <string>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    //if the sum goes below 0 do not let it go below 0 
    //this is kadane algorithm
     long long sum=0;
     int maxi=INT_MIN;
     for(int i=0;i<nums.size();i++){
         sum+=nums[i];
         if(sum>maxi){
             maxi=sum;
         }
         if(sum<0){
             sum=0;
         }
     }
     return maxi;
    }
};
