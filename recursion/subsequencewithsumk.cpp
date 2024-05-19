#include<bits/stdc++.h> 
using namespace std;


void print(vector<int>t){
    for(int i=0;i<t.size();i++){
        cout<<t[i];
    }
    cout<<endl;
}
void solve(int i,vector<int>nums,vector<int> t,int sum,int target){
    if(i==nums.size()){
        if(sum==target){
            print(t);
        }
        return;
    }
    
    //take case
    t.push_back(nums[i]);
    sum+=nums[i];
    solve(i+1,nums,t,sum,target);

    //notake case
    t.pop_back();
    sum-=nums[i];
    solve(i+1,nums,t,sum,target);

}

int main(){
    vector <int> t;
    vector<int> nums = {1,2,1};
    int target = 2;
    solve(0,nums,t,0,target);
}