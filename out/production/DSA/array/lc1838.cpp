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
    //total cost ka funa bass
    int maxFrequency_solution(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int s = k;
        int maxfreq = 0;
        int r =0;
        long long int sum=0;
        while(r<n){
            sum+=nums[r];
            long long int cost = (long long) nums[r] * (r-l+1)-sum;
            while(cost>k){
                sum-=nums[l];
                l++;
                cost=(long long) nums[r] * (r-l+1)-sum;
            }

            maxfreq = max(maxfreq,(r-l+1));
            r++;
           
        }
        return maxfreq; 
    }