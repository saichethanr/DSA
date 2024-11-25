#include<bits/stdc++.h> 
using namespace std;

 int maxAbsoluteSum(vector<int>& nums) {
        int maxsumpos = INT_MIN;
        int maxsumneg = INT_MIN;
        int sum =0;
        for(int num : nums){
            sum+=num;
            maxsumpos = max(maxsumpos,sum);
            if(sum<0){
                sum=0;
            }
        }
        sum =0;
        for(int num : nums){
            sum+=num;
            maxsumneg = max(maxsumneg , abs(sum));
            if(sum>0){
                sum=0;
            }
        }
        return max(maxsumpos,maxsumneg);
    }