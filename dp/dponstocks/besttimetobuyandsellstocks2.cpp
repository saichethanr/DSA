#include<bits/stdc++.h> 
using namespace std;


//u can buy n number of times and sell n number of times 
//but when bought u need to sell it 


//whther u can buy the stiok or not is maintained by the buy variable
//once u go  out of the datwes range of buy and sell then even if u are hollding a stok it of no use
//for buying u would loose amount 
//for selling u would gain amount hence its + and - alternatively
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