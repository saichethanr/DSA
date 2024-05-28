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