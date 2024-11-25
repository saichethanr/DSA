#include<bits/stdc++.h> 
using namespace std;
void  binsearch(vector <int> &v,int s,int e, int n,int target){
    if(e<s){
        return ;
    }
    int m = (s+e)/2;
    if(v[m]==target){
        cout<<m<<endl;
    }
    if(v[m]>target){
        binsearch(v,s,m-1,n,target);
    }
    else{
        binsearch(v,m+1,e,n,target);
    }
}
int main(){
    vector <int> v = {10,20,30,89,97,102};
    int target = 89;
    int s=0;
    int n = v.size();
    int e = v.size()-1;
    binsearch(v,s,e,n,target);
    
    return 0;
}