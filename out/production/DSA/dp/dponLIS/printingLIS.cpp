 #include<bits/stdc++.h> 
using namespace std;



    //space optimized approach
   int lengthOfLIS(vector<int>& nums) {
         int n = nums.size();
         vector<int>dp(n,1),hash(n);
         int maxi = INT_MIN;
         int lastindx =0;

         for(int ind=0;ind<n;ind++){
              hash[ind] =ind;
              for(int prev=0;prev<ind;prev++){
                if((nums[prev]<nums[ind]) && ((1 + dp[prev]))>dp[ind]){
                    dp[ind] = 1+ dp[prev];
                    hash[ind] = prev;
                }  
              }

              if(dp[ind]>maxi){
                maxi = dp[ind];
                lastindx = ind;
              }
              maxi = max(maxi,dp[ind]);
         }
        //  int the hash array u are storing the index of the last iindex on beeing updated
         vector<int>ans(n,0);
         ans[0] = nums[lastindx];
         int idx= 1;
         while(hash[lastindx]!=lastindx){
            lastindx = hash[lastindx];
            ans[idx++] = nums[lastindx];
         }
         reverse(ans.begin(),ans.end());
         for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
         }
         return maxi;
    }