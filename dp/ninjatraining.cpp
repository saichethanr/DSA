#include<bits/stdc++.h> 
using namespace std;
int rec(int day, vector<vector<int>> &points,int last){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }

    int maxi =0;
   
    for(int i=0;i<3;i++){
        if(i!=last){
           int point = points[day][i] + rec(day-1,points,i);
            maxi = max(maxi,point);
        }
    }
    return maxi;
}

int topdowndp(int day, vector<vector<int>> &points,int last, vector<vector<int>> &dp){
    if(day==0){
        int maxi=0;
        for(int i=0;i<3;i++){
            if(i!=last){
                maxi = max(maxi,points[0][i]);
            }
        }
        return maxi;
    }
   
   if(dp[day][last]!=-1){
       return dp[day][last];
   }
    int maxi =0;
   
    for(int i=0;i<3;i++){
        if(i!=last){
           int point = points[day][i] + topdowndp(day-1,points,i,dp);
            maxi = max(maxi,point);
        }
    }
    dp[day][last] = maxi;
    return dp[day][last];
}

int bottomup(int day, vector<vector<int>> &points, vector<vector<int>> &dp){
  
  dp[0][0] = max(points[0][1],points[0][2]);
  dp[0][1] = max(points[0][0],points[0][2]);
  dp[0][2] = max(points[0][1],points[0][0]);
  dp[0][3] = max(points[0][1],points[0][2],points[0][0]);

for(int d =0;d<day;d++){
    for(int l=0;l<4;l++){
        dp[d][l]=0;
          for(int i=0;i<3;i++){
              if(i!=l){
           int point = points[day][i] + dp[d-1][l];
           dp[d][l] = max(dp[d][l],point);
        }
    }
    
    }
}
return dp[day-1][3];
}