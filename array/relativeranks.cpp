#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue <int> pq;
        for(int i=0;i<score.size();i++){
            pq.push(score[i]);
        }
        int n= score.size();
        unordered_map <int,int> mpp;
        int i=1;
        while(!pq.empty()){
            int t = pq.top();
            pq.pop();
            mpp[t] =i;
            i++; 
        }

        vector<string> ans(n,"");
        for(int i=0;i<score.size();i++){
            if(mpp[score[i]]==1){
                ans[i] = "Gold Medal";
            }
            else if(mpp[score[i]]==2){
                ans[i] = "Silver Medal";
            }
            else if(mpp[score[i]]==3){
                ans[i] = "Bronze Medal";
            }
            else{
                string str = to_string(mpp[score[i]]);
                ans[i] = str;
            }
        }
        return ans;
    }
};