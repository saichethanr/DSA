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


      int minDistance(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        //conveert the problem inot 1 based indexing 
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        //as its 1 based indexing its just initialized to i and not i+1
        for(int i=1;i<=n1;i++){
            dp[i][0] = i;
        }

        for(int j=0;j<=n2;j++){
            dp[0][j] = j;
        }

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){

                //if the char match run this if not run the esle
                 if(s1[i-1]==s2[j-1]){
                        dp[i][j] = 0 + dp[i-1][j-1];
                 }
                 else{
                         int insert = 1 + dp[i][j-1];
                int replace =1 +  dp[i-1][j-1];
                int del  = 1 + dp[i-1][j];
                dp[i][j] = min(insert,min(replace,del));
                    
                 }
            
            }
        }
        return dp[n1][n2];
    }