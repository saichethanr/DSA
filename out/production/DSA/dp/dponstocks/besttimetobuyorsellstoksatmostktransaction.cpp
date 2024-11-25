#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
         int n = prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
                

        for(int ind=0;ind<prices.size();ind++){
             for(int buy=0;buy<=1;buy++){
                dp[ind][buy][0] = 0;
             }
        }

        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=k;cap++){
                dp[n][buy][cap] = 0;
            }
        }
        

        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                     int profit=0;
                        if(buy){
                            //if u can buy u should loose amount 
                        profit = max(-prices[ind]+dp[ind+1][0][cap],dp[ind+1][1][cap]);

                        }
                        else{
                            //if u sell u can gain amount
                            profit = max(prices[ind]+dp[ind+1][1][cap-1],dp[ind+1][0][cap]);
                        }
                        dp[ind][buy][cap] = profit;
                }
            }
        }
      
        
        return dp[0][1][k];
    }
};