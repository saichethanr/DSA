#include<bits/stdc++.h> 
#include <vector>
using namespace std;
bool arrsortcheck(vector <int> v,int i,int n){
if(i==n-1){
    return true;
}

if(v[i+1]<v[i]){
    return false;
}
return arrsortcheck(v,i+1,n); 
}
int main(){
    vector <int> v = {1,1,1,1};
    cout<<arrsortcheck(v,0,v.size())<<endl;
    return 0;
}