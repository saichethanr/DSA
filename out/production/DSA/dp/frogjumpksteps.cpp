#include<bits/stdc++.h> 
using namespace std;


int simplerec(int idx,vector<int> &heights,int k){
    //base case 
    if(idx==0){
        return 0;
    }
    int minstep =INT_MAX;
    for(int j=1;j<=k;j++){
        if(idx-j>=0){
            int jump = simplerec(idx-j,heights,k) + abs(heights[idx]-heights[idx-j]);
            minstep = min(minstep,jump);
        }
    }
 
    return minstep;
}

int memo(int idx,vector<int> &heights,vector <int> &dp,int k){
    //base case 
    if(idx==0){
        return 0;
    }
       
    if(dp[idx]!=-1){
        return dp[idx];
    }

   int minstep =INT_MAX;
   for(int i=0;i<=idx;i++){
    minstep =INT_MAX;
       for(int j=1;j<=k;j++){
        if(idx-j>=0){
            int jump = memo(i-j,heights,dp,k) + abs(heights[i]-heights[i-j]);
            minstep = min(minstep,jump);
        }
    }
     dp[i] = minstep;
   }
   
    
    
return dp[idx];
}

int tab(int idx,vector<int> &heights,vector <int> &dp,int k){
 //base case 
    dp[0]=0;
   
   int minstep =INT_MAX;
   for(int i=1;i<=idx;i++){
    minstep =INT_MAX;
       for(int j=1;j<=k;j++){
        if(i-j>=0){
            int jump = dp[i-j] + abs(heights[i]-heights[i-j]);
            minstep = min(minstep,jump);
        }
    }
     dp[i] = minstep;
   }
    return dp[idx];
}




