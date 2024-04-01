#include<bits/stdc++.h> 
using namespace std;
// There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

// In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

// Your score is the sum of the points of the cards you have taken.

// Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

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