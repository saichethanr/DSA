#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    bool ispalindrome(int n){
        string s = to_string(n);
        string temp = s;
        reverse(s.begin(),s.end());
        if(s==temp){
            return true;
        }
        return false;
    }
    
bool isprime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}
    int primePalindrome(int n) {
        if(n<=2){
            return 2;
        }
        int t=n;
        if(t%2==0){
            t++;
        }

        while(true){
            if(ispalindrome(t) && isprime(t)){
                return t;
            }
            t+=2;
        }

        return t;

    }
};