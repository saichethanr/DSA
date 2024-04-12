  #include<bits/stdc++.h> 
using namespace std;

 int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int s = k;
        int maxfreq = INT_MIN;
        int r=n-1;
        while(l<=r){
           s=k;
           for(int i=r;i>=l;i--){
            if(s<=0){
                break;
            }
              if((nums[r]-nums[i])<=s){
                  s-=(nums[r]-nums[i]);
                  maxfreq = max(maxfreq,(r-i+1));
              }
           }
           
           r--;

        }
        return maxfreq; 
    }