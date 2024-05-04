 #include<bits/stdc++.h> 
using namespace std;


 int solve(int ind1,int ind2,string s1,string s2){
        if(ind1<0 || ind2<0){
            return 0;
        }

        if(s1[ind1]==s2[ind2]){
            return 1 + solve(ind1-1,ind2-1,s1,s2);
        }

        return max(solve(ind1,ind2-1,s1,s2),solve(ind1-1,ind2,s1,s2));
    }