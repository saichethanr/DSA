#include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    pair<long long, long long> getMinMax(long long a[], int n) {
        long long minel = LLONG_MAX; 
       long long maxel = LLONG_MIN;
       for(int i=0;i<n;i++){
           if(a[i]>maxel){
               maxel = a[i];
           }
       }
        for(int i=0;i<n;i++){
           if(a[i]<minel){
               minel = a[i];
           }
       }
       
        pair<long long, long long> p= {minel,maxel};
        return p;
    }
};