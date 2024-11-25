#include<bits/stdc++.h> 
#include <string>
using namespace std;    

// You are given an integer array nums.

// Return an integer that is the maximum distance between the indices of two (not necessarily different) prime numbers in nums.
class Solution {
public:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        vector <int> prime;
        for(int i=0;i<nums.size();i++){
            if(isPrime(nums[i])){
                prime.push_back(i);
            }
        }
        
        if(prime.size()==1){
            return 0;
        }
        int n=prime.size();
        return prime[n-1]-prime[0];
    }
};