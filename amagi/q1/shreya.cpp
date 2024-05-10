#include<bits/stdc++.h> 
using namespace std;

int solve(int w,vector<int>&rem){
    sort(rem.begin(),rem.end());
    int ans=0;
    int reqwork=0;
    for(int i=0;i<rem.size();i++){
        if(rem[i]==w){
            continue;
        }
        reqwork+=abs(rem[i]-w);
        ans++;
        if(reqwork>=w){
            break;
        }
    }
    if(reqwork<w){
        return -1;
    }
    return ans;
}
int main(){
    int w;
    cin>>w;
    int n;
    cin>>n;
    vector <int> rem(n);
    for(int i=0;i<n;i++){ 
        cin>>rem[i];
    }
    int ans = solve(w,rem);
    cout<<ans;
    return 0;
}