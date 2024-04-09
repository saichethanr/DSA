#include<bits/stdc++.h> 
using namespace std;


int simplerec(int idx,vector<int> &heights){
    //base case 
    if(idx==0){
        return 0;
    }

    int left = simplerec(idx-1,heights) +  abs(heights[idx]-heights[idx-1]);
    int right = INT_MAX;
    if(idx>1){
         right = simplerec(idx-2,heights) + abs(heights[idx]-heights[idx-2]);
    }
    

    return min(left,right);
}

int memo(int idx,vector<int> &heights,vector <int> &dp){
    //base case 
    if(idx==0){
        return 0;
    }
       
    if(dp[idx]!=-1){
        return dp[idx];
    }

    int left = memo(idx-1,heights,dp) +  abs(heights[idx]-heights[idx-1]);
    int right = INT_MAX;
    if(idx>1){
         right = memo(idx-2,heights,dp) + abs(heights[idx]-heights[idx-2]);
    }
    
    

    dp[idx] = min(left,right);
    return dp[idx];
}

int tab(int idx,vector<int> &heights,vector <int> &dp){
  dp[0] = 0;
    for (int i = 1; i <= idx; i++) {
        int left = dp[i - 1] + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;
        if (i > 1) {
            right = dp[i - 2] + abs(heights[i] - heights[i - 2]);
        }

        dp[i] = min(left, right);
    }

    return dp[idx];
}

int tab(int idx,vector<int> &heights){
  int previ=0;
  int prev2i=0;

  for(int i=0;i<=idx;i++){
     int left = previ + abs(heights[i]-heights[i-1]);
     int right = INT_MAX;
     if(i>1){
        right = prev2i + abs(heights[i]-heights[i-2]);
     }  
     int curi = min(left,right);
     prev2i=previ;
     previ = curi;

  }
  return previ;
}


