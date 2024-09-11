#include<bits/stdc++.h> 
#include <vector>
using namespace std;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long int ans =0;
        int sum1=0;
        int z1=0;
        int z2=0;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]!=0){
               sum1+=nums1[i];
            }
            else{
               z1++;
            }
        }

        int sum2=0;
        for(int i=0;i<nums2.size();i++){
            if(nums2[i]!=0){
                sum2+=nums2[i];
            }
            else{
                z2++;
            }
        }
        
       if(z2==0 || z1==0){
           return -1;
       }

        if(sum2>sum1){
           ans = sum2 + z2;
        }
        else if(sum1>sum2){
           ans = sum1 + z1;
        }
        else if(sum1==sum2){
           
            ans = sum1 + z1 + z2;
        }
        


   
      return ans;
    }
};