#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int diff=-1;
        int x;
        for(int i=0;i<nums1.size();i++){
             x = nums2[i]-nums1[i];
           
        }
        return x;
    }
};