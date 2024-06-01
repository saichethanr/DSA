#include<bits/stdc++.h> 
using namespace std;
//brute force approach giving TLE
class Solution {
public:
    bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            return (n & (n - 1)) == 0;
    }
    int sum=0;
    int cnt=0;
    int countPairs(vector<int>& deliciousness) {
        for(int i=0;i<deliciousness.size();i++){
            for(int j=i+1;j<deliciousness.size();j++){
                  sum = deliciousness[i] + deliciousness[j];
                  if(isPowerOfTwo(sum)){
                    cnt++;
                  }
            }
        }
        return cnt;
    }
};