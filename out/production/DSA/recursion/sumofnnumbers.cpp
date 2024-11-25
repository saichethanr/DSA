#include<bits/stdc++.h> 
#include <vector>
using namespace std;


int solve(int n){
     if(n==0){
        return 0;
     }
     return n+solve(n-1);
}
int main(){
     int ans = solve(3);
     cout<<ans<<endl;   
}