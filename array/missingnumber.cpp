#include<bits/stdc++.h> 
using namespace std;
int missingNumber(vector<int>& array, int n) {
       int sum = (n*(n+1))/2;
       int s=0;
       for(int i=0;i<array.size();i++){
           s+=array[i];
       }
       return sum - s;
    }