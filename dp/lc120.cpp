#include<bits/stdc++.h> 
using namespace std;

int solve_rec(int i,int j,int n,vector<vector<int>>& a){
            if(i==n-1){
                return a[n-1][j];
            }

            int down = a[i][j] + solve_rec(i+1,j,n,a);
            int dia = a[i][j] + solve_rec(i+1,j+1,n,a);
          return min(down,dia);
}