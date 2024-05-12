 #include<bits/stdc++.h> 
using namespace std;

//string a can be converted to string b
//by 
//insert
//repplace
//delete

    int solve(int i,int j,string s1, string s2){
        //first string s empty but we can constructing second string using insert operation
        if(i<0){
            return j+1;
        }
        //second string is empty
        //first string can be converted to second by deleting the first 
        if(j<0){
            return i+1;
        }

 

        if(s1[i]==s2[j]){
           return 0 + solve(i-1,j-1,s1,s2);
        }
        int insert = 1 + solve(i,j-1,s1,s2); //hypothetical insertion in the first string 
        int replace =1 +  solve(i-1,j-1,s1,s2); ////hypothetical insertion in the first string 
        int del  = 1 + solve(i-1,j,s1,s2);//deletion done in the first string 

        return min(insert,min(replace,del));
    }


    int solve(int i,int j,string s1, string s2,vector<vector<int>>&dp){
        //first string s empty but we can constructing second string using insert operation
        if(i<0){
            return j+1;
        }
        //second string is empty
        //first string can be converted to second by deleting the first 
        if(j<0){
            return i+1;
        }
        

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
 

        if(s1[i]==s2[j]){
           dp[i][j] = 0 + solve(i-1,j-1,s1,s2,dp);
           return dp[i][j];
        }
        int insert = 1 + solve(i,j-1,s1,s2,dp);
        int replace =1 +  solve(i-1,j-1,s1,s2,dp);
        int del  = 1 + solve(i-1,j,s1,s2,dp);

       dp[i][j] =  min(insert,min(replace,del));
       return dp[i][j];;
    }