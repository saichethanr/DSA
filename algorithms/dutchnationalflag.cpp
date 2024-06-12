#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch national flag algorithm
        //arr of 0 to low-1 --> 0 (should contain zero)
        //low to mid-1 contains 1
        //high+1 to n-1 2
        int mid=0;
        int s=0;
        int h = nums.size()-1;
        while(mid<=h){
            if(nums[mid]==0){
                swap(nums[mid],nums[s]);
                s++;
                mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
              swap(nums[mid],nums[h]);
              h--;
            }
        }


    }
};