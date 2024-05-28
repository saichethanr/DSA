#include<bits/stdc++.h> 
using namespace std;


//u can buy n number of times and sell n number of times 
//but when bought u need to sell it 


//whther u can buy the stiok or not is maintained by the buy variable
//once u go  out of the datwes range of buy and sell then even if u are hollding a stok it of no use
//for buying u would loose amount 
//for selling u would gain amount hence its + and - alternatively

//TC 2pown
class Solution {
public:
    int f(int ind,int buy,vector<int>& prices) {
        if(ind==prices.size()){
            return 0;
        }
        int profit=0;
        if(buy){
            //if u can buy u should loose amount 
           profit = max(-prices[ind]+f(ind+1,0,prices),f(ind+1,1,prices));

        }
        else{
            //if u sell u can gain amount
            profit = max(prices[ind]+f(ind+1,1,prices),f(ind+1,0,prices));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int ans = f(0,1,prices);
        return ans;
    }
};


//changing parameter ind and buy
//dp size n and 2
//memoization approach
class Solution {
public:
//tc N*2
    int f(int ind,int buy,vector<int>& prices,vector<vector<int>> &dp) {
        if(ind==prices.size()){
            return 0;
        }
        int profit=0;
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        if(buy){
            //if u can buy u should loose amount 
            //its a simple case of buy and not buy 
           profit = max(-prices[ind]+f(ind+1,0,prices,dp),f(ind+1,1,prices,dp));
           

        }
        else{
            //if u sell u can gain amount
            //its a simple case of buy or not buy
            profit = max(prices[ind]+f(ind+1,1,prices,dp),f(ind+1,0,prices,dp));
        }

        dp[ind][buy] = profit;
        return dp[ind][buy];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        int ans = f(0,1,prices,dp);
        return ans;
    }
};

//memoization is the dpiation of the code we have 
//we need to tablulate now 

class Solution {

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        //base cases    
        dp[n][1]=0;
        dp[n][0] =0;

        for(int ind = n-1;ind>=0;ind--){
           for(int buy=0;buy<=1;buy++){
                        int profit=0;
                      
                        if(buy){
                            //if u can buy u should loose amount 
                            //its a simple case of buy and not buy 
                        profit = max(-prices[ind]+dp[ind+1][0],dp[ind+1][1]);
                        

                        }
                        else{
                            //if u sell u can gain amount
                            //its a simple case of buy or not buy
                            profit = max(prices[ind]+dp[ind+1][1],dp[ind+1][0]);
                        }

                        dp[ind][buy] = profit;
           }
        }
        return dp[0][1];
    }
};
