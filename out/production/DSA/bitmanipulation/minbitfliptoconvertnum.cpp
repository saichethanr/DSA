// A bit flip of a number x is choosing a bit in the binary representation of x and flipping it from either 0 to 1 or 1 to 0.

// For example, for x = 7, the binary representation is 111 and we may choose any bit (including any leading zeros not shown) and flip it. We can flip the first bit from the right to get 110, flip the second bit from the right to get 101, flip the fifth bit from the right (a leading zero) to get 10111, etc.
// Given two integers start and goal, return the minimum number of bit flips to convert start to goal.

#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    int noofzerobits(int n){
          int cnt =0;
            while(n!=0){
                n = n&(n-1);
                cnt++;
            }
        return cnt;
    }
    int minBitFlips(int start, int goal) {
        int k = start^goal;
   
        int ans = noofzerobits(k);
        return ans;
    }

};
