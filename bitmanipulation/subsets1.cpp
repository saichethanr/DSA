#include<bits/stdc++.h> 
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int subset = 1<<n;
        vector<vector<int>> ans;
        for(int num = 0;num<subset;num++){
            vector <int> list;
            for(int i=0;i<nums.size();i++){
                  if(num & (1<<i)){
                    list.push_back(nums[i]);
                  }
            }
            ans.push_back(list);
        }
        return ans;
}


int main(){
    vector <int> nums = {1,2,2};
    vector<vector<int>>p = subsets(nums);
    for(int i=0;i<p.size();i++){
        for(int j=0;j<p[i].size();j++){
            cout<<p[i][j];
        }
        cout<<endl;
    }
}