// Two children, Lily and Ron, want to share a chocolate bar. Each of the squares has an integer on it.

// Lily decides to share a contiguous segment of the bar selected such that:

// The length of the segment matches Ron's birth month, and,
// The sum of the integers on the squares is equal to his birth day.
// Determine how many ways she can divide the chocolate.


#include<bits/stdc++.h> 
using namespace std;

int birthday(vector<int> s, int d, int m) {
   int n = s.size();
   int l=0;
   int r=0;
   int cnt=0;
   int sum=0;
   while(r<n){
       sum+=s[r];
       if((r-l+1)==m){
           if(sum==d){
               cnt++;
           }
           sum-=s[l];
           l++;
       }
       r++;
   }
   return cnt;
}