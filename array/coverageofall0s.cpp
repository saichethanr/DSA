#include<bits/stdc++.h> 
using namespace std;
class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        int sum=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    if(i-1>=0){
                        if(matrix[i-1][j]==1){
                            sum++;
                        }
                    }
                    if(i+1<matrix.size()){
                        if(matrix[i+1][j]==1){
                            sum++;
                        }
                    }
                    if(j-1>=0){
                         if(matrix[i][j-1]==1){
                            sum++;
                        }
                    }
                    if(j+1<matrix[0].size()){
                          if(matrix[i][j+1]==1){
                            sum++;
                        }
                    }
                }
            }
        }
        return sum;
    }
};