#include<bits/stdc++.h> 
using namespace std;

//you can flip the rows and colums such that given 2n*2n matrix the top n*n matrix sum has to be maximum


int flippingMatrix(vector<vector<int>> matrix) {
   int n = matrix.size();
   int sum=0;
   for(int i=0;i<n/2;i++){
       for(int j=0;j<n/2;j++){
           int cur =max({matrix[i][j],matrix[n-i-1][j],matrix[i][n-j-1],matrix[n-i-1][n-j-1]});
           sum+=cur;
       }
   }
   return sum;
}