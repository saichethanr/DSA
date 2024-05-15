#include<bits/stdc++.h> 
using namespace std;


//iterative approach TLE
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countGoodNumbers(long long n) {
        long long evenChoices = 1; 
        long long oddChoices = 1;  
         long long nextEven;
         long long nextOdd;
        for (long long i = 0; i < n; ++i) {

            if(i%2==0){
                nextEven = (evenChoices * 5) % MOD;
            }
            else{
                 nextOdd = (oddChoices * 4) % MOD; 
            }
      

            evenChoices = nextEven;
            oddChoices = nextOdd;
        }

    
        return (evenChoices * oddChoices) % MOD;
    }
};



class Solution {
public:
    const int MOD = 1e9 + 7;
    void solve(long long  i,long long n,long long int &ans){
         if(i>=n){
            return;
         }

         if(i%2==0){
            ans =(ans*5)%MOD;
            solve(i+1,n,ans);
         }
         else{
           ans = (ans*4)%MOD;
           solve(i+1,n,ans);
         }

    }
    int countGoodNumbers(long long n) {
         long long int ans =1;
        solve(0,n,ans);
         return ans;
    }
};