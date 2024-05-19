#include<bits/stdc++.h> 
using namespace std;

//find the absolute diffrence between he sum of the two diagonals

int diagonalDifference(vector<vector<int>> arr) {
     int suml=0;
     for(int i=0;i<arr.size();i++){
         suml+=arr[i][i];
     }
     int n = arr.size();
     int sumr=0;
     int j=n-1;
     for(int i=0;i<n;i++){
         sumr+=arr[i][j];
         j--;
     }
     
     return abs(sumr-suml);
     
}