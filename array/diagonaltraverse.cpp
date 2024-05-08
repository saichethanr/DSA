  #include<bits/stdc++.h> 
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r=0;
        int c=0;
        int row = mat.size();
        int col = mat[0].size();
        vector<int> ans;
        bool going_up = true;
        while(ans.size()!=(row*col)){
            if(going_up){
                while(r>=0 && c<col){
                    ans.push_back(mat[r][c]);
                    r-=1;
                    c+=1;
                }
                if(c==col){
                    r+=2;
                    c-=1;
                }
                else{
                    r+=1;
                }
                going_up=false;
            }
            else{
                while(r<row && c>=0){
                    ans.push_back(mat[r][c]); 
                    c-=1;
                    r+=1;
                }
                if(r==row){
                    c+=2;
                    r-=1; 
                }
                else{
                    c+=1;
                }
                going_up=true;
            }
        }
        return ans;
    }
};