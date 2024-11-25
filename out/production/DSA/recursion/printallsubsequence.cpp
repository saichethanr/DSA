#include<bits/stdc++.h> 
using namespace std;

void print(vector<int> t){
  for(int i=0;i<t.size();i++){
     cout<<t[i]<<" ";
  }
}
void solve(int i,vector<int> nums,vector<int>t){
    if(i==nums.size()){
        print(t);
        cout<<endl;
        return;
    }

    t.push_back(nums[i]);
    solve(i+1,nums,t);
    t.pop_back();

    solve(i+1,nums,t);
}

int main(){
    vector <int> nums= {3,1,2};
    vector <int> t;
    solve(0,nums,t);
}