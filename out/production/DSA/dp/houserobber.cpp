#include<bits/stdc++.h> 
using namespace std;

//house robber 


int robrec(vector <int> nums,int n){
    //basecase
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    // include and go left 2 index
    int include  = robrec(nums,n-2) + nums[n];
    //exclude and go left 1 index
    int exclude = robrec(nums,n-1) + 0;
    return max(include,exclude);
}
int robmem(vector <int> nums,int n,vector <int> &dp){
    //base case 
    if(n<0){
        return 0;
    }
    if(n==0){
        return nums[0];
    }
    
    //check whether if the value exits
    if(dp[n]!=-1){
        return dp[n];
    }

    // include and go left 2 index
    int include  = robmem(nums,n-2,dp) + nums[n];
    //exclude and go left 1 index
    int exclude = robmem(nums,n-1,dp) + 0;
    dp[n] = max(include,exclude);
    return dp[n];
}
int robtab(vector <int> nums,int n){
      vector <int> dp(n+1,0);

      dp[0]=nums[0];

      for(int i=1;i<=n;i++){
           int include =0;
           
    // include and go left 2 index
    if(i-2>=0){
        include  = dp[i-2] + nums[i];
    }
    //exclude and go left 1 index
    int exclude = dp[i-1] + 0;
    dp[i] = max(include,exclude);
    }
  return dp[n];
}

int robtab2(vector <int> nums,int n){
      vector <int> dp(n+1,0);

      dp[0]=nums[0];

      for(int i=1;i<=n;i++){
           int include =0;
           
    // include and go left 2 index
    if(i-2>=0){
        include  = dp[i-2] + nums[i];
    }
    //exclude and go left 1 index
    int exclude = dp[i-1] + 0;
    dp[i] = max(include,exclude);
    }
  return dp[n];
}

int spaceopti(vector <int> nums,int n){
    int prev =  nums[0];
    int prev2 = 0;
    for(int i=0;i<n;i++){
        int take = nums[i];
        if(i>1){
            take += prev2;
        }
        int donttake = 0 + prev;
        int curi = max(take,donttake);
        prev2 = prev;
        prev = curi;
    }
    return prev;
}
int main(){
    vector <int> nums = {1,2,3,1};
    int n=nums.size()-1;
    // int ans  =robrec(nums,n);
    // cout<<ans<<endl;
    vector <int> dp(n+1,-1);
    cout<<robtab(nums,n)<<endl;
    return 0;
}