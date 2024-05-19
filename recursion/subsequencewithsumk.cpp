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


//this is for prining just one subsequence 
bool f(int i,vector<int>nums,vector<int> t,int sum,int target){
    if(i==nums.size()){
        if(sum==target){
            print(t);
            return true;
        }
        return false;
    }
    
    //take case
    t.push_back(nums[i]);
    sum+=nums[i];
    //if the condition satifies if u dont want to call further recursive calls
    if(f(i+1,nums,t,sum,target) == true){
        return true;
    }
    //notake case
    t.pop_back();
    sum-=nums[i];
    if(f(i+1,nums,t,sum,target)==true){
        return true;
    }
  return false;
}
//this is to count the no of subsequence
int count(int i,vector<int>nums,vector<int> t,int sum,int target){
    if(i==nums.size()){
        if(sum==target){
            print(t);
            return 1;
        }
        return 0;
    }
    
    //take case
    t.push_back(nums[i]);
    sum+=nums[i];
    int take = count(i+1,nums,t,sum,target);

    //notake case
    t.pop_back();
    sum-=nums[i];
    int notake = count(i+1,nums,t,sum,target);
    //in such questions where we would need the count just add dup the take and no take case and return
    return take+notake;

}



int main(){
    vector <int> t;
    vector<int> nums = {2,3,5};
    int target = 8;
    solve(0,nums,t,0,target);
   
}