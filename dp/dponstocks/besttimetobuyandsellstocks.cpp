#include<bits/stdc++.h> 
using namespace std;


//we just have to find the maximum diffrence between any two elements such that the minimum element is at the begining 
//and the greater element is after the minimum element
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit=0;
        for(int i=1;i<prices.size();i++){
           profit = max(profit,prices[i]-mini);
           mini = min(prices[i],mini);
        }
        return profit;
    }
};