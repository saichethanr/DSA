#include<bits/stdc++.h> 
using namespace std;

class Solution {
public:
    bool dfs(int i,int j,int len,vector<vector<char>>& board,string word){
       if(word.size()==len){
         return true;
       }

       if(i<0 || i>=board.size() || j<0  || j>=board[0].size() || board[i][j]!=word[len]){
        return false;
       }

       char ch = board[i][j];
       board[i][j] =' ';
       //as its given that horizontally or vertially neigbhouring do not need to consider diagonal elements
       bool ans = dfs(i-1,j,len+1,board,word) || dfs(i,j-1,len+1,board,word) || dfs(i+1,j,len+1,board,word) || dfs(i,j+1,len+1,board,word);
       board[i][j] = ch;
       return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word){
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,0,board,word)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};