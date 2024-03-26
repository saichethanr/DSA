#include<bits/stdc++.h> 
using namespace std;
   int solverec(vector<int>& coins, int amount){
        if(amount==0){
            return 0;
        }

        if(amount <0){
            return INT_MAX;
        }

        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solverec(coins,amount-coins[i]);
            if(ans != INT_MAX){
                mini = min (mini,ans+1);
            }            
        }
        

        return mini;
    }

    //memoization
    int solvetopdown(vector<int>& coins, int amount,vector <int> dp){
        //base case 
        if(amount==0){
            return 0;
        }
         if(amount <0){
            return INT_MAX;
        }

        //base case ke just bad check karo exist karta hai ki nahi
        if(dp[amount]!=-1){
            return dp[amount];
        }

        int mini = INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = solvetopdown(coins,amount-coins[i],dp);
            if(ans != INT_MAX){
                mini = min (mini,ans+1);
            }            
        }
        //jha pe bhi asn nikal rhe ho vha store kro
        dp[amount] =mini;
        return dp[amount];    
    }

    //tabulation
    int solvetab(vector <int> coins, int amount){
        //dp[i] represents the minum no of coins needed to make that amount
        //hence as it is minimum we have to store the INT_MAX for each and every variable   
        vector <int> dp (amount+1,INT_MAX);
    
        //see the base case and execute
         dp[0] =0;
         //0-->target
         for(int i=1;i<amount;i++){

            int mini = INT_MAX;
            for(int j=0;j<coins.size();j++){
                
                if(i-coins[j]>=0){
                        int ans = dp[i-coins[j]];
                         if(ans != INT_MAX){
                              mini = min (mini,ans+1);
                        }  
                }
            }
            dp[i]=mini;
         }
         return dp[amount];
    }
    int main() {
      vector<int> coins = {1,2,5};
      int amount =11; 
    //  int ans = solverec(coins,amount);
    //  if(ans==INT_MAX){
    //      return -1;
    //  }
    //  cout<<ans<<endl;
    vector <int> dp (amount +1 , -1);
    int ans = solvetopdown(coins,amount,dp);
    }