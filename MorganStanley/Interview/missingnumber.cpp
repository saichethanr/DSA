#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> arr,int n){
    unordered_map<int,int>mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]++;
    }
    //1 --- >> n
    for(int i=1;i<=n;i++){
        if(mpp.find(i)==mpp.end()){
            return i;
        }
    }
    return -1;
}




int main(){
    vector<int> arr = {1,2,3,5};
    int n = 5;
    int ans = solve(arr,5);
    int a = n*(n-1);
}