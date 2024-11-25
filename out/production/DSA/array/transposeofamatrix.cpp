#include<bits/stdc++.h> 
using namespace std;


// } Driver Code Ends
class Solution
{   
    public:  
    //Function to find transpose of a matrix.
    void transpose(vector<vector<int> >& matrix, int n)
    { 
        vector<vector<int>>ans(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = matrix[j][i];
            }
        }
        
        matrix = ans;
    }
};