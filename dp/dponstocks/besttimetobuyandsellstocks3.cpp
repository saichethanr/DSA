#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int f(int ind,int buy,vector<int>& prices,int cap) {
        if(ind==prices.size()){
            return 0;
        }
        if(cap==0){
            return 0;
        }
        int profit=0;
        if(buy){
            //if u can buy u should loose amount 
           profit = max(-prices[ind]+f(ind+1,0,prices,cap),f(ind+1,1,prices,cap));

        }
        else{
            //if u sell u can gain amount
            profit = max(prices[ind]+f(ind+1,1,prices,cap-1),f(ind+1,0,prices,cap));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
         int ans = f(0,1,prices,2);
        return ans;
    }
};

//now as there are three unlonown variables its difficult you should have a 3d matrix
//ind-->N
//buy->2
//cap-->3
//dp[N][2][3]


//memoization code

class Solution {
public:
    int f(int ind,int buy,vector<int>& prices,int cap, vector<vector<vector<int>>> &dp) {
        if(ind==prices.size()){
            return 0;
        }
        if(cap==0){
            return 0;
        }
        
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        int profit=0;
        if(buy){
            //if u can buy u should loose amount 
           profit = max(-prices[ind]+f(ind+1,0,prices,cap,dp),f(ind+1,1,prices,cap,dp));

        }
        else{
            //if u sell u can gain amount
            profit = max(prices[ind]+f(ind+1,1,prices,cap-1,dp),f(ind+1,0,prices,cap,dp));
        }
        dp[ind][buy][cap] = profit;
        return dp[ind][buy][cap];
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        int ans = f(0,1,prices,2,dp);
        return ans;
    }
};