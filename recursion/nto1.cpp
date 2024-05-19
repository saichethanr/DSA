#include<bits/stdc++.h> 
#include <vector>
using namespace std;


void solve(int i,int n){
     if(i<1){
        return;
     }
     cout<<i<<endl;
     solve(i-1,n);
}
int main(){
     solve(7,1);
}