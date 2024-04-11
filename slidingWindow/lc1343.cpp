 #include<bits/stdc++.h> 
using namespace std;

 int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int l=0;
        int r=0;
        int cnt =0;
        int n = arr.size();
        int sum=0;
        while(r<n){
            sum+=arr[r];
            if((r-l+1)==k){
                int thresh = sum/(r-l+1);
                if(thresh>=threshold){
                    cnt++;
                }
                sum-=arr[l];
                l++;
            }
            r++;
        }
        return cnt;
    }