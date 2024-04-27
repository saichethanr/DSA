#include <bits/stdc++.h> 
using namespace std;

int solve_rec(int idx,int wt,vector<int>&weight,vector<int>&val){
    if(idx==0){
        if(weight[0]<=wt){
           return val[0];
        }
        else{
            return 0;
        }
    }


    int nopick = solve_rec(idx-1,wt,weight,val);
    int pick = INT_MIN;
    if(wt>=weight[idx]){
        pick  = val[idx] + solve_rec(idx-1,wt-weight[idx],weight,val);
    }

    return max(pick,nopick);
}