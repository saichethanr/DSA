#include<bits/stdc++.h> 
using namespace std;
class Solution
{ 
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int solve(int n,int k){
        //if there is one floor attemps=1 0 foloor attempt ==0
        if(k==1 || k==0){
            return k;
        }
        
        //if there is a single egg then the no of attempts needed is the number of floors
        if(n==1){
            return k;
        }
        
        int mini = INT_MAX;
        int res;
        int x;
        for(int x=1;n<=k;x++){
            res = max(solve(n-1,k-1),solve(n,k-x));
            if(res<mini){
                mini = res;
            }
        }
        return mini+1;
        
    }
    int eggDrop(int n, int k) 
    {
        return solve(n,k);
    }
};