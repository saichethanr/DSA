#include<bits/stdc++.h> 
using namespace std;


int maxScore(vector<int>& cardPoints, int k) {
        int l=0;
        int maxsum = INT_MIN;
        int sum=0;
        int j=0;
        for(int r=0;r<cardPoints.size();r++){
             sum+=cardPoints[r];
             j++;
             while(j>k){
                sum-=cardPoints[l];
                j--;
                l++;
             }

             maxsum = max(maxsum,sum);

        }
        return maxsum;
}

int ans(vector<int>& cardPoints, int k) {
        int lsum=0;
        int rsum=0;
        int l = 0;
        int maxsum=INT_MIN;  
        int r = k-1;
        int e = cardPoints.size()-1;
        for(int i=0;i<=r;i++){
            lsum+=cardPoints[i];
        }
        maxsum = max(maxsum,lsum);
        
        for(int i=k-1;i>=0;i--){
            lsum-=cardPoints[i];
            rsum+=cardPoints[e];
            e--;
            maxsum = max(maxsum,lsum+rsum);
        }

        return maxsum;

    }