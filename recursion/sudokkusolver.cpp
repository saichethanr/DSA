#include<bits/stdc++.h> 
using namespace std;



class Solution {
public:
    //for each empty cell test for all the posible character that cvan be applied to that cell if we can then we will aplly it 
    // and solve the new board obtained
    bool solve(vector<vector<char>>&board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                //check for the first empty cell and aappliy recursion for each empty cell
                if(board[i][j]=='.'){
                    //for that empty cell check for each and evry value that can be tested
                    for(char c = '1' ;c<='9';c++){
                        if(isvalid(board,i,j,c)){
                            board[i][j] = c;
                            if(solve(board)){
                                return true;
                            }
                            else{
                                board[i][j] = '.';
                            }
                        }
                    }
                    return false;

                }

            }
        }
        //if we did not find any empty cell
        return true;
    }
    bool isvalid(vector<vector<char>>&board,int row,int col,char c){
        for(int i=0;i<9;i++){
            //check for the character in the row
            if(board[i][col]==c){
                 return false;
            }
            //check for the character in the column
            if(board[row][i]==c){
                return false;
            }
            //look in the 3*3 matrix in the matrix
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c){
                 return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};