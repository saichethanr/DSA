 #include<bits/stdc++.h> 
using namespace std;


string findLCS(int n, int m,string &s1, string &s2){
	    int n1  =  s1.size();
        int n2 = s2.size();
         vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
         for(int j=0;j<=n2;j++){
            dp[0][j] = 0;
         }
         for(int i=0;i<=n1;i++){
            dp[i][0] =0;
         }

         for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                   dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
                }

                
            }
         }

   
        int len = dp[n1][n2];	

		int i=n;
		int j=m;
		string ans = "";
		for(int k=0;k<len;k++){
			ans+='$';
		}
		int index = len-1;
		while(i>0 && j>0){
             if(s1[i-1]==s2[j-1]){
                 ans[index] = s1[i-1];
				 index--;
				 i--;
				 j--;

			 }
			 else if(dp[i-1][j]>dp[i][j-1]){
                     i=i-1;
			 }
			 else{
                 j=j-1;
			 }
		}

		return ans;
}