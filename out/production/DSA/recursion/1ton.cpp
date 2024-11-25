#include<bits/stdc++.h> 
#include <vector>
using namespace std;


void solve(int i,int n){
     if(i>n){
        return;
     }
     cout<<i<<endl;
     solve(i+1,n);
}
int main(){
     solve(1,7);
}