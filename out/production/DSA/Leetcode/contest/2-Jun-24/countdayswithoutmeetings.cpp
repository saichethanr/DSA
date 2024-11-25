#include<bits/stdc++.h> 
using namespace std;



class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        int cnt=0;
        vector <vector<int>> ans;
        vector <int> temp;
        for(int i=0;i<meetings.size();i++){
          if(ans.empty()){
            ans.push_back(meetings[i]);
          }
          else{
             if(ans.back()[1]>=meetings[i][0]){
                temp = {min(ans.back()[0],meetings[i][0]),max(meetings[i][1],ans.back()[1])};
                ans.back() = temp;
             }
             else{
                     ans.push_back(meetings[i]);
             }
          }
        }
        for(int i=0;i<ans.size()-1;i++){
            if((ans[i+1][0]-ans[i][1]-1)>0){
                cnt+=(ans[i+1][0]-ans[i][1]-1);
            }
            
        }
        int n=  ans.size();
        if(ans[n-1][1]<days){
            cnt+=(days-ans[n-1][1]);
        }
        if(ans[0][0]>1){
            cnt+=(ans[0][0]-1);
        }
        
        return cnt;
    }
};