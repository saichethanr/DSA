
#include<bits/stdc++.h> 
#include <vector>
using namespace std;
// Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

// Note that it is the kth smallest element in the sorted order, not the kth distinct element.

// You must find a solution with a memory complexity better than O(n2).
class Solution {
public:
    int kthSmallest_myapproach(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue <int,vector<int>,greater<int>> pq;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                pq.push(matrix[i][j]);
            }
        }

        while(k>1){
            pq.pop();
            k--;
        }

        return pq.top();
    }
};