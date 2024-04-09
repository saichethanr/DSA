#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int maxlenin = 0;
        int maxlendec = 0;
        int cnt_increasing = 0;
        int cnt_decreasing = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                cnt_increasing++;
                maxlenin = max(maxlenin, cnt_increasing);
            } else {
                cnt_increasing = 0; 
            }
        }

  
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i - 1] > nums[i]) {
                cnt_decreasing++;
                maxlendec = max(maxlendec, cnt_decreasing);
            } else {
                cnt_decreasing = 0; 
            }
        }

        
        return max(maxlenin + 1, maxlendec + 1); 
    }
};
