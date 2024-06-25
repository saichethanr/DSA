#include<bits/stdc++.h> 
using namespace std;
long long sumMatrix(long long n, long long q) {
        // code here
        if(q>n*2){
            return 0;
        }
        long long sum=n+1;
        long long d=abs(q-sum);
        return n-d;
        
        
    }